#include <iostream>
using namespace std;

class Human
{
protected:
    int height;
    int weight;
    int age;

public:
    int getHeight()
    {
        return height;
    }
    int getWeight()
    {
        return weight;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
};

class Male : public Human
{
protected:
    string color;

public:
    void sleep()
    {
        cout << "The male is sleeping.\n";
    }
    void setColor(string color)
    {
        this->color = color;
    }
    void setHeight(int height)
    {
        this->height = height;
    }
};

int main()
{
    Male m;
    m.sleep();
    // cout << m.getHeight();
    m.setHeight(32);
    m.setAge(10);
    m.setColor("Jai Shri Ram!");
    cout << m.getAge() << endl;
    cout << m.getHeight() << endl;

    return 0;
}