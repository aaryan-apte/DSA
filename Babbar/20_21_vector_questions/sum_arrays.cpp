#include <bits/stdc++.h>
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    // Write your code here.

    int sum = 0, n1 = 0, n2 = 0;
    for (int i = 0; i < n; i++)
    {
        n1 = n1 + a[i] * pow(10, n - i - 1);
    }
    for (int i = 0; i < m; i++)
    {
        n2 = n2 + b[i] * pow(10, m - i - 1);
    }
    sum = n1 + n2;
    int size = 0, sum1 = sum, digits = 0;
    while (sum1 > 0)
    {
        sum1 = sum1 / 10;
        digits++;
    }
    vector<int> solution(digits);
    for (int i = digits - 1; i >= 0; i--)
    {
        solution[i] = sum % 10;
        sum = sum / 10;
    }
    return solution;
}