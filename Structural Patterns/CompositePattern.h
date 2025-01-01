#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* COMPOSITE DESIGN PATTERN
* Composes objects into treelike structures to represent whole-part hierarchies
* Provides a unified interface for individual onjects and compositions of objects
* 
* Makes it easier to handle complex object hierarchies
* 
*/

class Product // Abstract class
{
public:
	virtual double price() const = 0;
	virtual ~Product() = default;
};

class Book : public Product
{
public:
	Book(const string& title, double price) : m_Title(title), m_Price(price) {}

	double price() const override
	{
		cout << "Getting \"" << m_Title << "\" book price \n";
		return m_Price;
	}

private:
	string m_Title;
	double m_Price;
};

class Toy : public Product
{
public:
	Toy(const string& name, double price) : m_Name(name), m_PriceTag(price) {}
	double price()const override
	{
		cout << "Getting \"" << m_Name << "\" toy price \n";
		return m_PriceTag;
	}

private:
	string m_Name;
	double m_PriceTag;
};

// Box Class that holds products and other boxes

class Box : public Product// COMPOSITE
{
private:
	string m_Name;
	std::vector<Product*> m_Products;

public:
	explicit Box(const string& name) : m_Name(name) {}
	
	void addProduct(Product& product)
	{
		m_Products.push_back(&product);
	}

	double price() const override
	{
		cout << "Opening " << m_Name << endl;
		double totalPrice = 0;

		for (const auto& product : m_Products) totalPrice += product->price();
		
		return totalPrice;
	}
};


// CHALLENGE
// Abstract base class for concrete Shape classes
class Shape
{
public: 
	virtual void draw() const = 0;
	virtual ~Shape() = default;

};

// Concrete Shape classes
class Circle : public Shape
{
public:
	explicit Circle(double radius) : m_Radius(radius) {}

	void draw() const override
	{
		cout << "Drawing a Circle with Radius " << m_Radius << endl;

	}

private:
	double m_Radius;
};

class Triangle : public Shape
{
public:
	Triangle(double side1, double side2, double side3) : m_Side1(side1), m_Side2(side2), m_Side3(side3) {}
	void draw() const override
	{
		cout << "Drawing a Rectangle with sides" << m_Side1 << ", " << m_Side2 << " and " << m_Side3 << endl;

	}

private:
	double m_Side1;
	double m_Side2;
	double m_Side3;

};

class Rectangle : public Shape
{
public:
	Rectangle(double width, double height) : m_Width(width), m_Height(height) {}
	void draw() const override
	{
		cout << "Drawing a Rectangle with Width " << m_Width << " and Height " << m_Height << endl;

	}

private:
	double m_Width;
	double m_Height;

};

class CompositeShape : public Shape
{
private: 
	std::vector <Shape*> m_Shapes;
public:	
	void addShape(Shape& shape)
	{
		m_Shapes.push_back(&shape);

	}

	void removeShape(Shape& shape)
	{
		for (auto removedShape = m_Shapes.begin(); removedShape != m_Shapes.end(); removedShape++)
		{
			if (*removedShape == &shape)
			{
				m_Shapes.erase(removedShape);
				break;
			}
		}

	}

	void draw() const override
	{
		cout << "Drawing Composite Shape\n";

		for (const auto& shape : m_Shapes)
		{
			shape->draw();
		}
	}

};