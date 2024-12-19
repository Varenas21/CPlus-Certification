#include "Operators.h"

void CommonOperators() {
	auto x = 5;
	auto y = 47;

	cout << x << endl;
	cout << y << endl;

	x = y;
	cout << "New x value: " << x << endl;

	x = y % x;
	if (x == y) cout << "true\n";
	else cout << "false\n";
	cout << "New x value: " << x << endl;

	bool a{ true };
	bool b = false;

	cout << "Value A: " << a << endl;
	cout << "Value B: " << b << endl;
	cout << "Size of A: " << sizeof(a) * 8 << endl;

	if (a && b) cout << "true\n";
	else cout << "false\n";

	// COMPOUND OPERATORS
	x += y; 
	cout << "New x value: " << x << endl;
	x -= y;
	cout << "New x value: " << x << endl;
	x *= y;
	cout << "New x value: " << x << endl;
	x /= y;
	cout << "New x value: " << x << endl;
	x %= y;
	cout << "New x value: " << x << endl;
}

unsigned long Factorial(unsigned long n)
{
	if (n < 2) return 1;
	return n * Factorial(n - 1);
}



void PointerIncrement(const int_type* p) {
	cout << static_cast<const void*>(p) << endl;
	cout << *p << endl;

	unsigned long n{ 5 };
	cout << "Factorial of n is " << Factorial(n);
}

