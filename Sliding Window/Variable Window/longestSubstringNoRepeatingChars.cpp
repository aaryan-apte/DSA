#include <iostream>
using namespace std;

bool checkUnique(int nums[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (nums[i] > 1)
            return false;
    }
    return true;
}

int longestUnique(string s)
{
    int i = 0, j = 0, sizeSub = 0;
    int nums[26] = {0};

    while (i < s.length() && j < s.length())
    {
        if (checkUnique(nums))
        {
            int pos = (int)s[j] - (int)'a';
            nums[pos]++;
            j++;
        }
        else
        {
            int pos = (int)s[i] - (int)'a';
            nums[pos]--;
            i++;
        }
        if (checkUnique(nums))
        {
            if (sizeSub < j - i)
                sizeSub = j - i;
        }
    }
    return sizeSub;
}

int main()
{
    string s = "jaiiiiishawertioplkmnbvc";
    cout << longestUnique(s);

    return 0;
}