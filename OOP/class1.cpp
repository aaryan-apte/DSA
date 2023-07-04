#include <iostream>
#include <vector>
// #include "classFile.cpp"
using namespace std;

class Hero
{
    int health;

public:
    void setHealth(int value)
    {
        if (value > 10)
        {
            cout << "Setting not allowed beyond 10";
            return;
        }
        health = value;
    }
    int getHealth()
    {
        return health;
    }
};

int main()
{
    Hero *h = new Hero;
    h->setHealth(9);
    cout << h->getHealth();

    // Hero ram;

    // ram.setHealth(5);
    // cout << ram.getHealth();
    // ram.health = 10;
    // ram.level = 5;                   // WORKS WHEN PROPERTIES ARE PUBLIC
    // ram.name = "Ram";
    // cout << ram.level << " name: " << ram.name << " health: " << ram.health;

    return 0;
}