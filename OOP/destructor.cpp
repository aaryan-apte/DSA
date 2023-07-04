#include <iostream>
#include <vector>
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

    ~Hero()
    {
        cout << "Pralay!!!\n";
    }

    void printData() const
    {
        cout << "Health: " << health << "\nName: " << name << endl;
    }
};

int main()
{
    Hero Ram(10, "Ram");
    Hero *h = new Hero(10, "Shyam");
    Ram.printData();
    delete h; // Dynamic allocated object sathi delete swataha lihava lagta.
    return 0; // Swatahun destructor call fakta static allocated obj sathi hoto.
}