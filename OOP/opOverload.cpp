#include <iostream>
using namespace std;

class Hero
{
public:
    int a;
    int b;

    void operator+(Hero &h)
    {
        int a1 = h.a;
        int a2 = this->a;
        cout << a1 - a2 << endl;
    }

    void operator()()
    {
        cout << "() overload jhala!\n\a";
    }
};

int main()
{
    Hero Ram;
    Hero Krishna;
    Krishna.a = 8;
    Ram.a = 9;
    Krishna + Ram;
    Krishna();
    return 0;
}