#include <iostream>
using namespace std;

bool isEqual(int ans[26], int toCompare[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (ans[i] != 0 && ans[i] > toCompare[i])
            return false;
    }
    return true;
}

int minWindow(string s, string t)
{
    int ans[26] = {0};
    for (int i = 0; i < t.length(); i++)
    {
        int pos = (int)t[i] - (int)'a';
        ans[pos]++;
    }

    int i = 0, j = 0, size = 0;
    int toCompare[26] = {0};

    while (j < s.length() && i < s.length())
    {
        if (size == 0)
            size = j - i;

        while (i < s.length() && isEqual(ans, toCompare))
        {
            if (size > j - i)
            {
                size = j - i;
            }

            int pos = (int)s[i] - (int)'a';
            toCompare[pos]--;
            i++;
        }
        while (j < s.length() && !isEqual(ans, toCompare))
        {
            int pos = (int)s[j] - (int)'a';
            toCompare[pos]++;
            j++;
        }
    }
    return size;
}

int main()
{
    string s = "ramatoc";
    string t = "toc";
    cout << minWindow(s, t);

    return 0;
}