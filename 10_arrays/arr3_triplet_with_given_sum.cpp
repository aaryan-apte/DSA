#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int s;
    cout << "Enter sum value:";
    cin >> s;

    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] > s)
        {
            continue; // for all a[i] > 0 only!
        }

        for (int j = i + 1; j < n - 1; j++)
        {
            if (a[j] + a[i] > s)
            {
                continue; // for all a[j] > 0 only!
            }

            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] + a[k] == s)
                {
                    cout << a[i] << " " << a[j] << " " << a[k] << endl;
                }
            }
        }
    }

    return 0;
}
