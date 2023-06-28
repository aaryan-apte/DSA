#include <iostream>
#include <vector>
using namespace std;

bool canSum(int n, vector<int> arr)
{
    vector<bool> mem(n + 1, false);
    mem[0] = true;
    for (int i = 0; i <= n; i++)
    {
        if (mem[i])
        {
            for (int j = 0; j < arr.size(); j++)
            {
                if (i + arr[j] <= n)
                {
                    mem[i + arr[j]] = true;
                }
                if (mem[n])
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 3, 8, 9};
    cout << canSum(70000000, arr);

    return 0;
}