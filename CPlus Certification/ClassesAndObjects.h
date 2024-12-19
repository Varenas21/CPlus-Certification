#pragma once
#include <iostream>
using namespace std;
class C1 {
	int c1Val{};
public:
	void setValue(int value) { c1Val = value; }
	int getValue() { return c1Val; }
};

// Interface
class Animal {
	string a_type;
	string a_name;
	string a_sound;
public:
	Animal(); //Default Constructor
	Animal(const string& type, const string& name, const string& sound);
	Animal(const Animal&);
	~Animal(); // Destructor
	Animal& operator = (const Animal&); // Copy/Assignment operator
	void print() const;
};

const string nanstr{ "{NAN}" };
class Rational {
	int n{ 0 };
	int d{ 1 };
public:
	Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {} // Default Constructor
	Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) {}
	~Rational();
	int numerator() const { return n; };
	int denominator() const { return d; };
	Rational Reduce() const;
	string str() const;
	string raw_str() const;
	Rational& operator = (const Rational&);
	Rational operator + (const Rational&) const;
	Rational operator - (const Rational&) const;
	Rational operator * (const Rational&) const;
	Rational operator / (const Rational&) const;

};