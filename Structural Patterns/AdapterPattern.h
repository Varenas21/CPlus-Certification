#pragma once
#include <iostream>

using namespace std;

class Component {
public:
    virtual void run() = 0;
    virtual ~Component() = default;

};

class ConcreteComponentA : public Component //Inherit and implement from Component Class
{
public:
    virtual void run() override
    {
        cout << "Executing ConcreteComponentA::run()" << endl;
    }
};

class ConcreteComponentB : public Component //Inherit and implement from Component Class
{
public:
    virtual void run() override
    {
        cout << "Execute ConcreteComponentB::run()" << endl;
    }
};

// Legacy Component (Incompatible Class)
class LegacyComponent
{
public:
    void go()
    {
        cout << "Executing LegacyComponent::go()" << endl;
    }
};


// USING OBJECT ADAPTER
 /*
 * Will create LegacyAdapter that inherits Component
 * Does not cause us to change the LegacyComponent
 */
class LegacyAdapter : public Component
{
public:
    // Define Constructor, initialize m_adaptee
    LegacyAdapter() : m_adaptee(make_unique<LegacyComponent>()) {}
    virtual void run() override
    {
        cout << "LegacyAdapter::run() -> calling LegacyComponent::go()" << endl;
    }
private:
    // Wraps component member, will be private
    unique_ptr<LegacyComponent> m_adaptee;
};

// USING CLASS ADAPTER
class LegacyClassAdapter : public Component, private LegacyComponent
{
public:
    virtual void run() override
    {
        cout << "LegacyClassAdapter::run() -> calling LegacyComponent::go()" << endl;
        go();
    }
};