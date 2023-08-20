#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        string number = "";

        int i = 0;
        char op;

        while (i < s.length() && s[i] == ' ')
            i++;

        if (s[i] == '+' || s[i] == '-')
            op = s[i];

        int num = (int)s[i] - (int)'0';

        while (i < s.length() && num <= 9 && num >= 0)
        {
            number += s[i];
            i++;
            num = (int)s[i] - (int)'0';
        }

        long long int ans;
        i = 0;
        while (i < number.length())
        {
            ans = ans * 10 + (int)number[i] - (int)'0';
            i++;
        }
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;

        return ans;
    }
};

int main()
{
    Solution s;
    s.myAtoi("r");
    return 0;
}