#include <iostream>
using namespace std;

void alternate_array(int a[], int n)
{
    int temp;
    // cout << temp;
    for (int i = 0; i < n - 1; i = i + 2)
    {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
    for (int i = 0; i < n; i++)
        cout << a[i];
}

void duplic_among_1_to_n_1(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
        ans = ans ^ i;
    }
    cout << ans;
}

void more_than_once_among_1_to_n_1(int a[], int n)
{
    int ans = 0;
    int b[n];
    int b_count = 0;
    for (int i = 0; i < n; i++)
        +
        {
            ans = ans ^ a[i];
            ans = ans ^ i;
        }
    cout << ans;
}

int main()
{
    int a[6] = {1, 2, 3, 4, 2, 5};
    duplic_among_1_to_n_1(a, 6);
    // alternate_array(a, 6);
    // for (int i = 0; i < 6; i++)
    //     cout << a[i];

    return 0;
}