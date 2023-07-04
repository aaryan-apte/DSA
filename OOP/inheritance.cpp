#include <iostream>
using namespace std;

class Aai
{
public:
    void ram()
    {
        cout << "Aai Krishna!\n";
    }
};

class Baba
{
public:
    void ram()
    {
        cout << "Baba Krishna!\n";
    }
};

class Aaryan : public Aai, public Baba
{
};

int main()
{
    Aaryan a;
    a.Aai::ram();

    return 0;
}