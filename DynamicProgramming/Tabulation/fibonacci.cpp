#include <iostream>
#include <vector>
using namespace std;

void fibTabulation(int n)
{
    vector<int> fib(n + 1, 0);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (auto i : fib)
        cout << i << " ";
}

int main()
{

    fibTabulation(40);

    return 0;
}