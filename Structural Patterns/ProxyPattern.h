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

#pragma endregion
