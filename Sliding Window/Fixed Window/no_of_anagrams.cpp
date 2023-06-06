#include <iostream>
#include <vector>
using namespace std;

bool areEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

int countAnagrams(string s1, string s2)
{
    int count = 0;
    int k = s2.length();
    int ans[26] = {0};
    for (int i = 0; i < k; i++)
    {
        int pos = (int)(s2[i]) - (int)('a');
        ans[pos]++;
    }

    int toCompare[26] = {0};

    for (int i = 0; i < k; i++)
    {
        int pos = (int)(s1[i]) - (int)('a');
        toCompare[pos]++;
    }
    if (areEqual(ans, toCompare))
        count++;
    for (int i = k; i < s1.length(); i++)
    {
        // char kadha
        int pos = (int)(s1[i - k]) - (int)('a');
        toCompare[pos]--;

        pos = (int)(s1[i]) - (int)('a');
        toCompare[pos]++;

        if (areEqual(ans, toCompare))
        {
            for (int j = i - k + 1; j <= i; j++)
            {
                cout << s1[j];
            }
            cout << endl;

            count++;
        }
    }

    return count;
}

int main()
{
    string s1 = "cbaebabacd";
    string s2 = "abc";
    cout << countAnagrams(s1, s2);

    return 0;
}