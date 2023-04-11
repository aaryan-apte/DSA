#include <iostream>
using namespace std;

// int isPossible(int arr[], int n, int m, int mid)
// {
// }

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    int a[100];
    int h = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        h = h + a[i];
    }
    int max = h;

    int m;
    cout << "Enter number of students:\n";
    cin >> m;
    int l = 0;

    int b[100];

    int mid = h / 2;
    int min = max;
    int selected;

    // while (l<=h)
    // {
    //     if(isPossible()){
    //         min = ans;
    //         e = mid -1;
    //     }
    //     else{

    //     }
    // }

    while (l < h)
    {
        selected = 1;
        int sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] + sum1 <= mid)
            {
                sum1 = sum1 + a[i];
            }
            else
            {
                b[selected - 1] = sum1;
                sum1 = a[i];
                selected++;
                if (selected > m)
                {
                    l = mid + 1;
                    break;
                }
            }
        }
        if (selected == m)
        {
            h = mid - 1;
            if (sum1 < min)
            {
                min = sum1;
            }
        }
        mid = l + (h - l) / 2;
    }
    // cout << min;
    for (int i = 0; i < selected - 1; i++)
    {
        cout << b[i] << " ";
    }

    // Hare Krishna!

    return 0;
}
