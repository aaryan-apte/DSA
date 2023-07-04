#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    Hero(int health)
    {
        cout << "Constructor called, Jay Shri Ram!\n";
        this->health = health;
    }
    Hero()
    {
        cout << "Constructor called, Jay Shri Ram!\n";
        health = 5;
    }

    int getHealth()
    {
        return health;
    }
};

int main()
{
    Hero Ram(10);
    cout << Ram.getHealth() << endl;

    // Hero *h = new Hero(7);
    // cout << h->getHealth() << endl;

    return 0;
}