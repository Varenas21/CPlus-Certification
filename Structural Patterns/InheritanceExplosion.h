#pragma once
#include <iostream>
using namespace std;


/*
* MAIN PROBLEM:
* We create a class for each variation
* MAIN SOLUTION USING BRIDGE:
* Separate common and specific parts of a design into distinct hierarchies
* COMMON:
* Message sharing logic
* DIFFERENT:
* The way messages are prepared and handled
* 
* TWO ABSTRACTIONS:
* ITextHandler - Message preparation and handling
* ITextSharer - Message Sharing
* 
*/

class ITextShare
{
public:
	virtual bool shareText(const string& text) = 0;
	virtual ~ITextShare() = default;

};

class EmailShare : public ITextShare
{
public:
	bool shareText(const string& text) override 
	{
		cout << "EmailShare::shareText() sharing text: " << text << endl;
		return true;
	}
};

class SMSShare : public ITextShare
{
public:
	bool shareText(const string& text) override
	{
		cout << "SMSShare::shareText() sharing text: " << text << endl;
		return true;
	}
};

class EmailShareEncrypted : public EmailShare
{
public:
	bool shareText(const string& text) override
	{
		cout << "EmailShareEncrypted::shareText() encrypting text..." << endl;
		string encrypted = xorEncrypt(text);
		return EmailShare::shareText(encrypted);
	}

private:
	string xorEncrypt(const string& input)
	{
		char key = 64;
		string output = input;

		for (int i = 0; i < input.size(); ++i)
			output[i] = input[i] ^ key; // ^ == XOR
		return output;
	}
};

class SMSShareEncrypted : public SMSShare
{
public:
	bool shareText(const string& text) override
	{
		cout << "SMSShareEncrypted::shareText() encrypting text..." << endl;
		string encrypted = xorEncrypted(text);
		return SMSShare::shareText(encrypted);
	}
private:
	string xorEncrypted(const string& input)
	{
		char key = 64;
		string output = input;

		for (int i = 0; i < input.size(); ++i)
			output[i] = input[i] ^ key; // ^ == XOR
		return output;

	}
};

class EmailShareAutoExpiring : public EmailShare
{

};

class SMSShareAutoExpiring : public SMSShare
{

};