#include <iostream>
using namespace std;

class Shape
{
public:
    float dim;

    virtual void area() = 0;
    virtual void volume() = 0;
};
class Square : public Shape
{
public:
    void area()
    {
        cout << "Area of square: " << dim * dim << endl;
    }
    void volume()
    {
        cout << "Volume of Cube: " << dim * dim * dim << endl;
    }
};

class Circle : public Shape
{
public:
    void area()
    {
        cout << "Area of Circle: " << 3.14 * dim * dim << endl;
    }
    void volume()
    {
        cout << "Volume of Sphere: " << (1.3333 * 3.14) * dim * dim * dim << endl;
    }
};

int main()
{
    Circle c;
    c.dim = 10;
    c.area();
    c.volume();

    Square s;
    s.dim = 10;
    s.area();
    s.volume();

    return 0;
}