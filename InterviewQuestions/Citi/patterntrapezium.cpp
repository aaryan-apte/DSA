#include <iostream>
using namespace std;

void printTrapezium(int n)
{
    int start = 1;
    int end = n * (n + 1);
    int startEnd = end - n + 1;
    int diff = n - 1;

    for (int i = 0; i < n; i++)
    {
        int j = 0;

        while (j < 2 * i)
        {
            cout << " ";
            j++;
        }

        j = n;
        while (j > i)
        {
            cout << start << "*";
            start++;
            j--;
        }
        j = n;
        while (j > i)
        {
            if (j == i + 1)
                cout << end << endl;
            else
                cout << end << "*";
            j--;
            end++;
        }
        end = startEnd - diff;
        diff--;
        startEnd = end;
    }
}

int main()
{
    printTrapezium(4);
    return 0;
}
