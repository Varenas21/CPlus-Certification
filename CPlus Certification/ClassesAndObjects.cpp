#include <iostream>
#include "ClassesAndObjects.h"

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