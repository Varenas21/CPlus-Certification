#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

/*
* The Proxy
* 
* Acts as a placeholder for another obkect
* Allows features such as lazy loading, access control and caching
* Provides a surrogate for another obkect to control access to it
* 
* Virtual
* Postpones the creation of objects until they are first needed
* Serves as a lightweight palceholder for objects that have a high creation cost
* Example: image will only load when the user requests it
* 
* Remote
* Provides a local placeholder used to control and optimize access to remote resources
* Intercepts and forwards requests to the remote resource
* Hides network communication details and complexity
* Example: Used to access web service without any need to write any network related code
* 
* Protective
* Provides controlled access
* Acts as a gatekeeper
* Example: Only authenticated users have access to proper web services
* 
* Pitfalls
* Increased complexity
* Added latency, decreased performance
*
*/

#pragma region ConfigFile

class ConfigFile
{
public:
	virtual vector<string> getSettings() = 0;
	virtual ~ConfigFile() = default;

};

// Define a concrete implementation of the ConfigFile
class RealConfigFile : public ConfigFile
{
public:
	explicit RealConfigFile(const string& filename)
	{
		cout << "RealConfigFile created. \n";
		// Open the file and read its contents into a vector of strings
		ifstream file(filename);
		string line;
		while (getline(file, line))
		{
			settings.push_back(line);
		}
		cout << settings.size() << " settings loaded. \n";

	}

	vector<string> getSettings() override
	{
		return settings;
	}
private:
	vector<string> settings;
};

class ConfigFileProxy : public ConfigFile
{
public:
	explicit ConfigFileProxy(const string& filename) : filename(filename), realConfigFile(nullptr)
	{
		cout << "Proxy Created \n";
	}


	vector<string> getSettings() override
	{
		if (realConfigFile == nullptr)
		{
			realConfigFile = make_unique<RealConfigFile>(filename);
		}
		return realConfigFile->getSettings();
	}

private:
	string filename;
	unique_ptr<RealConfigFile> realConfigFile;
};

#pragma endregion
#pragma region Challenge
// Implement a protective proxy that limits access to the SecureStorage class
// Validate secret code
// The proxy should expose the same interface as SecureStorage

class Storage
{
public:
	virtual const string getContents() = 0;
	virtual ~Storage() = default;

};

class SecureStorage : public Storage
{
public: 
	explicit SecureStorage(const string& data) : m_Contents(data) {}
	const string getContents()
	{
		return m_Contents;
	}
private:
	const string m_Contents;
};

class SecureStorageProxy : public Storage
{
public:
	explicit SecureStorageProxy(const string& data, const string& accessCode) : m_AccessCode(accessCode), m_SecureStorage(make_unique<SecureStorage>(data)) //Take data and access code
	{}

	const string getContents() override // Check that code matches
	{
		cout << "Code received \n";
		if (Authorized() == true)
		{
			return m_SecureStorage->getContents();
		}
		else
		{
			return "Access denied";
		}
	}
private:
	const string m_AccessCode;
	unique_ptr<SecureStorage> m_SecureStorage;
	bool Authorized()
	{
		return m_AccessCode == "Test";
	}
};
#pragma endregion

