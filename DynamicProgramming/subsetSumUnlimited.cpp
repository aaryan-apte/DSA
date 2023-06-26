#include <iostream>
// #include <vector>
using namespace std;

bool canSum(int targetSum, int num[], int n, int mem[1024])
{
    // bool ans = false;

    if (mem[targetSum] != -1)
        return mem[targetSum];

    if (targetSum == 0)
    {
        mem[targetSum] = true;
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (targetSum - num[i] >= 0)
        {
            mem[targetSum - num[i]] = canSum(targetSum - num[i], num, n, mem);
            return mem[targetSum - num[i]];
        }
    }
    return false;
}

int main()
{
    int num[2] = {4, 2};

    int mem[1024] = {-1};

    cout << canSum(7, num, 2, mem);
    cout << endl;
    for (int i = 0; i < 1024; i++)
    {
        if (mem[i] != -1)
            cout << mem[i] << endl;
    }

    return 0;
}