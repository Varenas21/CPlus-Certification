#pragma once
#include <iostream>
#include <string>

using namespace std;

/*
* DECORATOR DESIGN PATTERN
* 
* Allows adding new behaviors or functionalites to an object dynamically
* Wraps an object inside a decorator, which adds the new behavior
* 
* Extends the functionality of na object without subclassing
* Can add new methods or data members to an object without changing its interface
* Hides the wrapped object
* 
* Pitfalls
* A large number of decorators can make the code harder to understand
* Decorator hierarchies may get out of control
*/

#pragma region Example
class Computer 
{
public:
	virtual string description() const = 0;
	virtual double price() const = 0;
	virtual ~Computer() = default;
};

class Desktop : public Computer
{
public:
	string description() const override
	{
		return "Desktop";
	}

	double price() const override
	{
		return 1000.0;
	}
};

class Laptop : public Computer
{
public:
	string description() const override
	{
		return "Laptop";
	}

	double price() const override
	{
		return 1050.0;
	}
};

class ComputerDecorator : public Computer
{
public:
	explicit ComputerDecorator(Computer* computer) : m_Computer(computer) {}

	string description() const override
	{
		return m_Computer->description();
	}

	double price() const override
	{
		return m_Computer->price();
	}

protected:
	const Computer* m_Computer;
};

class MemoryUpgradeDecorator : public ComputerDecorator
{
public:
	explicit MemoryUpgradeDecorator(Computer* computer) : ComputerDecorator(computer) {}

	string description() const override
	{
		return ComputerDecorator::description() + " with memory upgrade \n";
	}

	double price() const override
	{
		return ComputerDecorator::price() + 500.0;
	}
};

class GraphicsUpgradeDecorator : public ComputerDecorator
{
public:
	explicit GraphicsUpgradeDecorator(Computer* computer) : ComputerDecorator(computer) {}

	string description() const override
	{
		return ComputerDecorator::description() + " with graphics upgrade \n";
	}

	double price() const override
	{
		return ComputerDecorator::price() + 1000.0;
	}
};


#pragma endregion

#pragma region Challenge
class Pizza
{
public:
	virtual string description() const = 0;
	virtual double price() const = 0;
	virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza
{
public:
	string description() const override
	{
		return "Margherita Pizza";
	}

	double price() const override
	{
		return 9.99;
	}
};

class HawaiianPizza : public Pizza
{
public:
	string description() const override
	{
		return "Hawaiian Pizza";
	}

	double price() const override
	{
		return 12.99;
	}
};

class PepperoniPizza : public Pizza
{
public:
	string description() const override
	{
		return "Pepperoni Pizza";
	}

	double price() const override
	{
		return 6.99;
	}
};

// Create a toppingdecorator that implements and wraps the pizza interface
class ToppingDecorator : public Pizza
{
public:
	explicit ToppingDecorator(Pizza* pizza) : m_Pizza(pizza) {}

	string description() const override
	{
		return m_Pizza->description();
	}

	double price() const override
	{
		return m_Pizza->price();
	}

protected:
	const Pizza* m_Pizza;

};

class ToppingMushroom : public ToppingDecorator
{
public:
	explicit ToppingMushroom(Pizza* pizza) : ToppingDecorator(pizza) {}
	string description() const override
	{
		return ToppingDecorator::description() + " with Mushrooms";
	}
	double price() const override
	{
		return ToppingDecorator::price() + 5.99;
	}
};

class ToppingTomato : public ToppingDecorator
{
public:
	explicit ToppingTomato(Pizza* pizza) : ToppingDecorator(pizza) {}
	string description() const override
	{
		return ToppingDecorator::description() + " with extra Sauce";
	}
	double price() const override
	{
		return ToppingDecorator::price() + 1.99;
	}
};

class ToppingCheese : public ToppingDecorator
{
public:
	explicit ToppingCheese(Pizza* pizza) : ToppingDecorator(pizza) {}
	string description() const override
	{
		return ToppingDecorator::description() + " with extra Cheese";
	}
	double price() const override
	{
		return ToppingDecorator::price() + 2.99;
	}
};


// Create a class for each type of topping
// Mushroom, tomato, extracheese

#pragma endregion
