#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (arr[i] == 0 && arr[j] == 0)
        {
            i++;
        }
        else if (arr[i] == 1 && arr[j] == 1)
        {
            j--;
        }
        else if (arr[i] == 1 && arr[j] == 0)
        {
            arr[i] = 0;
            arr[j] = 1;
        }
        else
        {
            i++;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
