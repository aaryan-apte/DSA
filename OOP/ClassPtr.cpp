#include <iostream>
using namespace std;

class Base
{
public:
    int base;
    void display()
    {
        cout << "Base class function called\n";
    }
};

class Derived : public Base
{
public:
    int derived;
    void display()
    {
        cout << "Derived class function called\n";
    }
};

int main()
{
    Derived d;
    d.display();
    Base *b;
    b = &d;
    b->display();

    return 0;
}