#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    // cout << "Enter value of n:\n";
    // cin >> n;
    // cout << endl;

    int a[6] = {2, 4, 1, 9, 8, 3};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX;
        int min_index = -1;
        for (int j = i; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                min_index = j;
            }
        }
        if (min_index != -1)
        {
            swap(a[i], a[min_index]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
