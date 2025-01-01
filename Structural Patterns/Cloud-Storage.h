#pragma once
#include <iostream>
#include <random>
#include <memory>


using namespace std;

class CloudStorage
{
public:
	virtual bool uploadContents(const string& content) = 0;
	virtual int getFreeSpace() = 0;
	virtual ~CloudStorage() = default;

};

class CloudDrive : public CloudStorage
{
public:
	bool uploadContents(const string& content) override
	{
		cout << "Uploading" << content.length() << " bytes to CloudDrive: " << endl;
		return true;
	}

	int getFreeSpace() override
	{
		//Implement the logic for getting the free space on CloudDrive here


		//const int size = arc4random_uniform(20); Not supported in windows
		// Generate a random number between 0 and 19
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(0, 19);

		int size = distr(gen); // Generate the random number
		cout << "Available CloudDrive Storage: " << size << "GB" << endl;
		return size;

	}

};

class FastShare : public CloudStorage
{
public:
	bool uploadContents(const string& content) override
	{
		cout << "Uploading " << content.length() << " bytes to FastShare: " << endl;
		return true;
	}

	int getFreeSpace() override
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(0, 9);

		int size = distr(gen); // Generate the random number
		cout << "Available FastShare Storage: " << size << "GB" << endl;
		return size;
	}
};

// 3RD PARTY SERVICE
class VirtualDrive
{
public:
	bool uploadData(const string& data, const int uniqueID)
	{
		cout << "Uploading to VirtualDrive: \"" << data << "\" ID: " << uniqueID << endl;
		return true;
	}
	int usedSpace()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(0, 9);

		int size = distr(gen); // Generate the random number
		return size;
	}
	const int totalSpace = 15;
};


class LegacyAdapterCloud : public CloudStorage, private VirtualDrive
{
public:
	LegacyAdapterCloud() : m_CloudAdaptee(make_unique<VirtualDrive>()) {}
	bool uploadContents(const string& content) override
	{
		const time_t uniqueID = time(nullptr);
		cout << "LegacyAdapterCloud::uploadContents() -> calling VirtualDrive::uploadData() \n";
		uploadData(content, uniqueID);
		return true;
	}

	int getFreeSpace() override
	{
		cout << "LegacyAdapterCloud::getFreeSpace() -> calling VirtualDrive::UsedSpace() \n";
		usedSpace();
		return 1;
	}

private:
	unique_ptr<VirtualDrive> m_CloudAdaptee;
};

