#include <iostream>
using namespace std;

class ITextHandler
{
public:
	virtual string prepareMessage(const string& text) const = 0;
	virtual ~ITextHandler() = default;
};

class ITextSharer
{
public:
	explicit ITextSharer(const ITextHandler& handler) : m_textHandler(handler) {}

	bool shareText(const string& text)
	{
		const string preparedText = m_textHandler.prepareMessage(text);
		return sharePreparedText(preparedText);
	}
	virtual ~ITextSharer() = default;

protected:
	virtual bool sharePreparedText(const string& text) = 0;
private:
	const ITextHandler& m_textHandler;
};

class PlainTextHandler : public ITextHandler
{
public:
	string prepareMessage(const string& text) const override
	{
		cout << "PlainTextHandler::prepareMessage() returning original text..." << endl;
		return text;
	}
};

class EmailShare : public ITextSharer
{
public:
	explicit EmailShare(const PlainTextHandler& handler) : ITextSharer(handler) {}
	bool sharePreparedText(const string& text) override
	{
		cout << "EmailShare::shareText() sharing text: " << text << endl;
		return true;
	}
};

class EncryptedTextHandler : public ITextHandler
{
public:
	string prepareMessage(const string& text) const override
	{
		cout << "EncryptedTextHandler::prepareMessage() encrypting text..." << endl;
		string encrypted = xorEncrypted(text);
		return encrypted;
	}
private:
	string xorEncrypted(const string& input) const
	{
		char key = 64;
		string output = input;

		for (int i = 0; i < input.size(); ++i)
			output[i] = input[i] ^ key; // ^ == XOR
		return output;

	}
};

class EmailShareEncrypted : public ITextSharer
{
public:
	explicit EmailShareEncrypted(const EncryptedTextHandler& handler) : ITextSharer(handler) {}
protected:
	bool sharePreparedText(const string& text) override
	{
		cout << "EmailShareEncrypted::shareText() sharing text: " << text << endl;
		return true;
	}
};

// CHALLENGE: VEHICLES AND ENGINES
/*
* Vehicle
* Car | Truck
*Car Gas | Car Electric  TruckGas | Truck Electric
* CarHybrid
* 
* Abstract
* IVehicle - +drive(), +driveVehicle() | Car Truck |
* IEngine - +start() | GasEngine ElectricEngine HybridEngine |
* void drive() const {
*	m_engine.start();
*	driveVehicle();
* }
*/



class IEngine
{
public:
	virtual void start() const = 0;
	virtual ~IEngine() = default;
};

class IVehicle
{
public:
	explicit IVehicle(const IEngine &engine) : m_engine(engine) {}

	virtual void drive() const
	{
		m_engine.start();
		driveVehicle();
	}
protected:
	virtual void driveVehicle() const = 0;
private:
	const IEngine &m_engine;
};

class GasEngine : public IEngine
{
public:
	void start() const override
	{
		cout << "Starting gas engine... \n";
	}
};

class ElectringEngine : public IEngine
{
public:
	void start() const override
	{
		cout << "Starting electric engine... \n";
	}
};

class HybridEngine : public IEngine
{
public:
	void start() const override
	{
		cout << "Starting hybrid engine... \n";
	}
};

class Car : public IVehicle
{
public:
	Car(const IEngine &engine) : IVehicle(engine) {}

	void driveVehicle() const override
	{
		cout << "Driving a car \n";
	}

};

class Truck : public IVehicle
{
public:
	Truck(const IEngine &engine) : IVehicle(engine) {}
	void driveVehicle() const override
	{
		cout << "Driving a truck \n";
	}
};