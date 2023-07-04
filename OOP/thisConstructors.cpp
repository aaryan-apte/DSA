#include <iostream>
using namespace std;

class Hero
{
    int health;
    string name;

public:
    Hero(int health, string name)
    {
        this->health = health;
        this->name = name;
        cout << "Constructor called, values set.\n";
    }

    Hero(Hero &temp)
    {
        this->health = temp.health;
        this->name = temp.name;
    }

    void get()
    {
        cout << "Health: " << health << "\nName: " << name << endl;
    }
};

int main()
{
    Hero Ram(10, "Ram");
    Ram.get();
    cout << "\nshyam\n";
    Hero Shyam(Ram);
    Shyam.get();

    cout << "\nKrishna\n";
    Hero Krishna(Ram);
    Krishna.get();

    return 0;
}