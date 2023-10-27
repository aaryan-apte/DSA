#include <iostream>
using namespace std;

class Parent
{
protected:
    string parentName;
};

class Child : protected Parent
{
private:
    int age;

public:
    void setAge(int age)
    {
        this->age = age;
    }
    void setParentName(string parentName)
    {
        this->parentName = parentName;
        cout << parentName << endl;
    }

    void getAge()
    {
        cout << "Age: " << age << endl;
    }
};

int main()
{
    Child c;
    c.setParentName("Ram");

    return 0;
}