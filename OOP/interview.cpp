#include <iostream>
#include <vector>
using namespace std;

int recFun(vector<vector<int>> &mat, int col, int row)
{
    if (col < 0 || row < 0)
    {
        return 0;
    }

    if (row >= mat.size())
        return 0;

    if (col == mat[0].size() - 1)
    {
        return mat[row][col];
    }

    int ans1 = mat[col][row] + max(recFun(mat, col + 1, row), recFun(mat, col + 1, row + 1), recFun(mat, col + 1, row - 1));
}

int main()
{

    return 0;
}