#include <iostream>
#include <vector>
using namespace std;

void gridTraveler(int m, int n)
{
    vector<vector<int>> grid(m + 1, vector<int>(n, 0));
    grid[1][1] = 1;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i < m)
                grid[i + 1][j] += grid[i][j];

            if (j < n)
                grid[i][j + 1] += grid[i][j];
        }
    }
    cout << grid[m][n];
}

int main()
{
    gridTraveler(3, 3);

    return 0;
}