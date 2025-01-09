#pragma once
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

/*
* Facade Pattern
* 
* Provides a simplified interface for a complex subssytem
* Hides complexity behind a higher-level API
* 
* Simpligies the use of complex subsystems, libraries or frameworks
* Decouples the consumer side from underlying frameworks
* Can be used to remove unneeded features or simplify their usage
* 
* PITFALLS
* Assigning too many responsibilites to a facade breaks the single-responsibility principle
* Exposing the underlying types defeats the facade's purpose
* 
*/

#pragma region Example
// Mock class for datbase library
class Database
{
public:
	void storeReservation(const string& reservation) { cout << "Database: Storing reservation: " << reservation << endl; }
	
};

//Mock Class for payment gateway
class PaymentGateway
{
public:
	void processPayment(const string& paymentInfo) { cout << "Payment Gateway: Processing payment info: " << paymentInfo << endl; }
};

// Mock class for messaging service
class MessagingService
{
public:
	void sendConfirmation(const string& message) { cout << "Messaging Service: Sending confirmation message: " << message << endl; }
};

class ReservationSystemFacade
{
public:
	ReservationSystemFacade() : m_Database(), m_PaymentGateway(), m_MessagingService() {}

	void makeReservation(const string& reservationInfo, const string& paymentInfo)
	{
		m_Database.storeReservation(reservationInfo);
		m_PaymentGateway.processPayment(paymentInfo);
		m_MessagingService.sendConfirmation("Reservation confirmed!");
	}

private:
	Database m_Database;
	PaymentGateway m_PaymentGateway;
	MessagingService m_MessagingService;
};

#pragma endregion

#pragma region Challenge
// Simplify application and insert simpler interface
// Create a WeatherFacade class that exposes the currentWeather() method, which takes the location as an argument
// WeatherFacade wraps the web service objects and delegates the calls to them, retunrs the combined weather data as a tuple

class WorlWeatherAPI
{
public:
	tuple<float, float, string> getWeather(string location)
	{
		cout << "Calling worldWeather with location: " << location << endl;
		float temperature = 20.0f;
		float windSpeed = 5.5f;
		string shortDescription = "Sunny";
		return make_tuple(temperature, windSpeed, shortDescription);
	}
};

class FreeWeather
{
public: 
	tuple<float, string> retrieveWeater(string location)
	{
		cout << "Calling freeWeather with location: " << location << endl;
		float temperature = 22.0f;
		string shortDescription = "Sunny";
		return make_tuple(temperature, shortDescription);
	}
};

class RealtimeWeatherService
{
public:
	tuple<float, float, string> weatherConditions(string location)
	{
		cout << "Calling RealtimeWeather with location: " << location << endl;
		float temperature = 19.5f;
		float humidity = 60.5f;
		string shortDescription = "{Partly cloudy with a chance of rain";
		return make_tuple(temperature, humidity, shortDescription);
	}
};

class WeatherFacade
{
public:
	WeatherFacade() : m_WWApi(), m_FWeather(), m_RWService() {}

	const tuple<float,float,string> currentWeather(const string& location)
	{
		auto WWApi = m_WWApi.getWeather(location);
		auto FWeather = m_FWeather.retrieveWeater(location);
		auto RWService = m_RWService.weatherConditions(location);
		
		float temperature = get<0>(WWApi);
		float humidity = get<1>(RWService);
		string shortDesc = get<1>(FWeather);

		return make_tuple(temperature, humidity, shortDesc);

	}

private:
	WorlWeatherAPI m_WWApi;
	FreeWeather m_FWeather;
	RealtimeWeatherService m_RWService;
};

#pragma endregion


