#include <iostream>
using namespace std;

class Complex
{
    int r;
    int i;

public:
    Complex(int r, int i)
    {
        this->i = i;
        this->r = r;
    }
    friend class Operations;
};

class Operations
{
public:
    pair<int, int> addComplex(Complex &c1, Complex &c2)
    {
        return {c1.r + c2.r, c1.i + c2.i};
    }
    pair<int, int> subComplex(Complex &c1, Complex &c2)
    {
        return {c1.r - c2.r, c1.i - c2.i};
    }
};

int main()
{
    Complex c1(10, 2), c2(2, 5);
    Operations op;
    pair<int, int> ansAdd = op.addComplex(c1, c2);
    cout << "Adding: " << ansAdd.first << endl;
    pair<int, int> ansSub = op.subComplex(c1, c2);
    cout << "Subtracting: " << ansSub.first;

    return 0;
}