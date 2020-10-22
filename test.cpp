// test.cpp
#include<iostream>
#include<stdio.h>
using namespace std;

class Base
{
private:
    /* data */
public:
    Base();
    ~Base();
    virtual void fun(){
        cout<<"\nBase Function";
    }
};

Base::Base()
{
    fun();
}

Base::~Base()
{
}

class Derived:public Base
{
private:
    
public:
    Derived();
    ~Derived();
    virtual void fun(){
        cout<<"\nDerived Function";
    }
};

Derived::Derived()
{
}

Derived::~Derived()
{
}

int main(int argc, char const *argv[])
{
    Base *pBase = new Derived();
    delete pBase;
    return 0;
}


