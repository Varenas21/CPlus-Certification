#include <iostream>
#include "Datatypes.h"
#include "Operators.h"
#include "ClassesAndObjects.h"

using std::cout;

int main()
{
	// === CHAPTER 1 - 4 ===
	////Pointers
	//Pointers();
	//// Conditionals
	//Conditional();
	//Datatypes();


	// Std == Standard, double colon scope operator
	//std::printf("The str is {}\n", str); // Faster than cout

	// Identifiers are case sensitive and they are 73 | 11 keywords and alternative tokens
	//const if it has an const it cannot change (constant variable value) 
    //auto allows compiler to determine the type of variable EX: auto i {47};

	// === CHAPTER 5 - 7 ===
	CommonOperators();
	int_type arr[]{ 1,2,3,4,5 };
	int_type* p = arr;
	PointerIncrement(p++);
	PointerIncrement(p++);
	PointerIncrement(p++);
	
	C1 o1;
	o1.setValue(47);
	cout << "value is " << o1.getValue();
	// Class defaults to private, Struct defaults to public
	// Good to use struct for only variables, class for functions

	//Animal a{};
	//a.print();

	//const Animal b("goat", "bob", "bahh");
	//b.print();

	//const Animal c = b;
	//c.print();

	//a = c;
	//a.print();

	//Rational b{ 4,3 };
	//cout << "20 + a = " << (20 + b).str();
	//cout << "20 - a = " << (20 - b).str();
	//cout << "20 * a = " << (20 * b).str();
	//cout << "20 / a = " << (20 / b).str();

	cout << "End of Main\n";
	return 0;
}


