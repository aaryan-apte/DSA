#include <iostream>
using namespace std;

bool isPossible(int a[], int k, int mid){
    int cow_count = 1;
}

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    int a[100];
    int h = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (h < a[i])
        {
            h = a[i];
        }
    }

    int k;
    cout << "Enter the number of aggressive cows:\n";
    cin >> k;

    int l = 0;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if(isPossible(a, k, mid)){

        }

    }

    return 0;
}
