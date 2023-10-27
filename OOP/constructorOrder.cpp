#include <iostream>
using namespace std;

// class A
// {
// public:
//     A()
//     {
//         cout << "A is called\n";
//     }
// };

// class Aa
// {
// public:
//     Aa()
//     {
//         cout << "Aa is called\n";
//     }
// };

// class B : public A
// {
// public:
//     B()
//     {
//         cout << "B is called\n";
//     }
// };

// class C : public A
// {
// public:
//     C()
//     {
//         cout << "C is called\n";
//     }
// };

// class D : virtual public A, public Aa
// {
// public:
//     D()
//     {
//         cout << "D is called\n";
//     }
// };

class Base1
{
public:
    int base1;
    Base1(int i)
    {
        base1 = i;
        cout << "Base1 is called\n";
    }
};

class Base2
{
public:
    int base2;
    Base2(int i)
    {
        base2 = i;
        cout << "Base2 is called\n";
    }
};

class Derived : public Base2, public Base1
{
public:
    int d1, d2;

    Derived(int a, int b, int c, int d) : Base2(b), Base1(a)
    {
        d1 = c;
        d2 = d;
        cout << "Derived called\n";
    }
};

int main()
{
    Derived d(1, 2, 3, 4);

    return 0;
}