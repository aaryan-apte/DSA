#include <iostream>
using namespace std;

bool twoDistinct(int nums[26])
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (nums[i] != 0)
        {
            count++;
            if (count > 2)
                return false;
        }
    }
    return true;
}

int longestSubstring(string s)
{
    int i = 0, j = 0, size = 0;
    int nums[26] = {0};
    while (i < s.length() && j < s.length())
    {
        if (twoDistinct(nums))
        {
            int pos = (int)s[j] - (int)'a';
            nums[pos]++;
            j++;
        }
        if (twoDistinct(nums) && size < j - i)
        {
            size = j - i;
        }
        else
        {
            int pos = (int)s[i] - (int)'a';
            nums[pos]--;
            i++;
        }
    }
    return size;
}

int main()
{
    string s = "abaabbcde";
    cout << longestSubstring(s);

    return 0;
}