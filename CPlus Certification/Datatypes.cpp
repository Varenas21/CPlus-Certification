#include <iostream>
#include <typeinfo>
#include <vector>
#include "Datatypes.h"

void Pointers() {
/*
* Variable type and name location in memory
* memory is allocated based on datatype and associated with a name
* Name is used as an index to map to a memory address
*
*/
//int x;
//x = 1;
//int y; // Represents a variable in another location in memory
//y = x; // It now contains the same value as X but is now in a different location under a different variable

// Pointer
//int* ip; Holds the address of another variable, poitner to an integer value
//ip = &x; Reference or address operator, assigns address of x to pointer (pointer points to the variable x)
//y = *ip; Dereferencing we access the value pointed to by the pointer. Equavilant of y = x;

	int x{ 7 };
	int* ip = &x;
	int& y = x; // Reference to an int

	cout << "The value of x is " << x << std::endl;
	cout << "The value of ip is " << *ip << std::endl;
	cout << "The value of y is " << y << std::endl;

	//int z{ 73 };
	//ip = &z;
	y = 42; // Changes the value of x

	//*ip = 42;

	cout << "The value of x is " << x << std::endl;
	cout << "The value of ip is " << *ip << std::endl;
	cout << "The value of y is " << y << std::endl;
}


struct S {
	int i{};
	double d{};
	const char* s{};
};

void Conditional() {
	auto x = 42;
	auto y = 7;

	if (x != y) { // 1 is true 0 is false
		cout << "Condition is true \n";
	}

	//Used for non complex statements
	auto s = x > y ? "yes" : "no"; // If the condition is true return first value (yes) otherwise return second value (no)
	cout << "S is " << s << std::endl;

	// LOOPS
	// While will continue while the condition is true, if it is not then it will exit out
	int array[]{ 1,2,3,4,5 };
	int i{ 0 };

	while (i < 5)
	{
		cout << "-- WHILE --" << std::endl;
		if (i == 3) {
			i++;
			continue;
		}
		cout << "Element in index i:" << i << std::endl;
		cout << "Element in array i: " << array[i] << std::endl;
		++i;
	}

	do {
		cout << "-- DO WHILE --" << std::endl;
		cout << "Element in index i:" << i << std::endl;
		cout << "Element in array i: " << array[i] << std::endl;
	} while (i < 5);

	// FOR 
	cout << "-- FOR --" << std::endl;
	const char string[]{ "string" };
	for (auto* p = string; *p; ++p)
	{
		cout << "Element in index i:" << i << std::endl;
		cout << "Char in array i: " << *p << std::endl;
	}

	for (const auto& e : string)
	{
		if (e == 0) break;
		cout << "Element is: " << e << std::endl;
	}
}

void Datatypes() {
	const size_t byte{ 8 };

	float f{};
	double df{};
	long double ldf{};

	cout << "Size of float is: " << sizeof(f) * byte << std::endl;
	cout << "Size of double is: " << sizeof(df) * byte << std::endl;
	cout << "Size of long double is: " << sizeof(ldf) * byte << std::endl;

	std::string s{ "This is a string" };
	auto x = s;
	cout << "x is " << x << std::endl;
	cout << "Type of x is " << typeid(x).name() << std::endl;

	std::vector<int> vi{ 1,2,3,4,5 };
	for (std::vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
	{
		cout << "int is " << *it << std::endl;
		cout << "Type of it is " << typeid(it).name();
	}
}

//typedef uint32_t points_t;
//typedef uint32_t rank_t;

using points_t = uint32_t;
using rank_t = uint32_t;

struct score {
	points_t p{};
	rank_t r{};
};

int Qualifiers() {
	score s{ 5,1 };
	cout << "Score s had " << s.p << "points and a rank of " << s.r << std::endl;

	// Structs
	S s1{ 3, 47.9, "string one" };
	auto* sp = &s1;
	sp->d = 73.0;
	cout << "s1 : " << s1.i << s1.d << s1.s << std::endl;


	static int x{ 7 }; // No longer discards or reinitializes with static
	return ++x;

}