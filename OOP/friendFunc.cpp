#include <iostream>
#include <string>
using namespace std;

class Complex;

class Operations
{
public:
    int getRealSum(Complex c1, Complex c2);
};
int Operations::getRealSum(Complex c1, Complex c2)
{
    return c1.r + c2.r;
}

class Complex
{
private:
    int r;
    int i;

public:
    friend class Operations;
    // friend int Operations::getRealSum(Complex, Complex);
    void addComplex(Complex &c)
    {
        this->r = this->r + c.r;
        this->i = this->i + c.i;
    }
    void minusComplex(Complex &c)
    {
        this->r = this->r - c.r;
        this->i = this->i - c.i;
    }
    Complex(int r, int i)
    {
        this->r = r;
        this->i = i;
    }
    friend string getComplex(Complex &c1);
};

string getComplex(Complex &c1)
{
    return to_string(c1.r) + '+' + to_string(c1.i) + 'i';
}

int main()
{
    Complex c1(1, 5);
    Complex c2(4, 2);
    c1.addComplex(c2);
    c2.minusComplex(c1);
    cout << getComplex(c1) << endl;
    cout << getComplex(c2) << endl;

    return 0;
}