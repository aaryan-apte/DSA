#include <iostream>
#include <vector>
using namespace std;

class Hero
{
    int health;
    string name;

public:
    static int time;
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

int Hero::time = 6;

int main()
{
    Hero Ram(10, "Ram");
    Hero *h = new Hero(10, "Shyam");

    cout << Hero::time << endl;
    Hero::time = 10;
    cout << Hero::time << endl;

    delete h;

    return 0;
}