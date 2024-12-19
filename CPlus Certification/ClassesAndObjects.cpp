#include <iostream>
#include "ClassesAndObjects.h"
#include <string>

const string unk{ "unknown" };
const string clone_prefix;

Animal::Animal() : a_type(unk), a_name(unk), a_sound(unk)
{
	cout << "Default Constructor\n";
}

Animal::Animal(const string& type, const string& name, const string& sound)
	: a_type(type), a_name(name), a_sound(sound)
{
	cout << "Construtor with arguments\n";
}

Animal::Animal(const Animal& a) {
	cout << "Copy constructor";
	a_name = clone_prefix + a.a_name;
	a_type = a.a_type;
	a_sound = a.a_sound;
}

Animal& Animal::operator = (const Animal& o)
{
	cout << "Assignment Operator\n";
	if (this != &o)
	{
		a_name = clone_prefix + o.a_name;
		a_type = o.a_type;
		a_sound = o.a_sound;
	}
	return *this;
}

void Animal::print() const {
	cout << a_name << a_type << a_sound << endl;
}

// Rational
Rational Rational::Reduce() const {
	if (n == 0 || d <= 3) return *this;
	for (auto div = d - 1; div; -div)
	{
		if (n % div == 0 && d % div == 0)
		{
			return Rational(n / div, d / div);
		}
	}
	return *this;
}

string Rational::str() const {
	if (d == 0) return nanstr;
	if (d == 1 || n == 0) return std::to_string(n);

	auto abs_n = abs(n);
	if (abs_n > d)
	{
		auto whole = n / d;
		auto remainder = abs_n % d;
		if (remainder) return std::to_string(whole) + " " + Rational(remainder, d).str();
		else return std::to_string(whole);
	}
	else
	{
		return Reduce().raw_str();
	}


}

string Rational::raw_str() const {
	return std::to_string(n) + "/" + std::to_string(d);
}

Rational& Rational::operator = (const Rational& rhs)
{
	if (this != &rhs)
	{
		n = rhs.numerator();
		d = rhs.denominator();
	}
	return *this;
}

// Non-Member Operators
Rational operator+(const Rational& lhs, const Rational& rhs) {
	return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.numerator() * rhs.numerator(), rhs.denominator() * rhs.denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

Rational::~Rational()
{
	n = 0; d = 1;
}


