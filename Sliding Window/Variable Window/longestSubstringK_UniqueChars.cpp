#include <iostream>
#include <vector>
using namespace std;

int countUnique(int nums[26])
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (nums[i] != 0)
            count++;
    }
    return count;
}

int longestSubstring(string s, int k)
{
    int i = 0, j = 0;
    int nums[26] = {0};
    int sizeSub = 0;
    while (i < s.length() && j < s.length())
    {
        while (i < s.length() && j < s.length() && countUnique(nums) <= k)
        {
            int pos = (int)s[j] - (int)'a';
            nums[pos]++;

            if (countUnique(nums) == k && sizeSub < j - i + 1)
            {
                sizeSub = j - i + 1;
            }
            j++;
        }

        while (i < s.length() && j < s.length() && countUnique(nums) > k)
        {
            int pos = (int)s[i] - (int)'a';
            nums[pos]--;
            i++;
        }
    }
    return sizeSub;
}

int main()
{
    // string s = "aabcbcdabcdccadca";
    string s = "aaaaaaaaabccccbbbbsf";
    cout << longestSubstring(s, 5);

    return 0;
}