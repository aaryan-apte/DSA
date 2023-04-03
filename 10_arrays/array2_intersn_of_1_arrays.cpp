#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter value of n and m:\n";
    cin >> n >> m;
    cout << endl;

    int a[n], b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int i = 0, j = 0, k = 0;
    int c[n + m];

    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            c[k++] = a[i];
            i++;
            j++;
        }
        if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
    }

    if (k != 0)
    {
        for (int i = 0; i < k; i++)
        {
            cout << c[i] << " ";
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}
