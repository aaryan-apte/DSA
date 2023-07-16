#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    // cout << "Enter value of n:\n";
    // cin >> n;
    // cout << endl;

    int a[6] = {3, 1, 5, 4, 2, 8};

    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        int index = i;
        while (index >= 0 && index <= i)
        {
            if (a[index] <= a[j] && a[index + 1] > a[j])
            {
                int temp = a[j];
                int index1 = j;
                while (index1 > index + 1)
                {
                    a[index1] = a[index1 - 1];
                }
                a[index + 1] = temp;
            }
            else if (a[index] > a[j])
            {
                index--;
            }
            // else if (a[index] < a[j])
            // {
            //     index++;
            // }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
