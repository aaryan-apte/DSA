#include <iostream>
// #include <string>
#include <vector>
using namespace std;

bool isStartingSubset(string target, string str)
{
    if (target.length() > str.length())
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (target[i] != str[i])
                return false;
        }
        return true;
    }
    return false;
}

string reduceTarget(string target, string str)
{
    // aahet subset...
    string result = "";

    for (int i = str.length(); i < target.length(); i++)
        result.push_back(target[i]);

    return result;
}

vector<vector<string>> canConstruct(string target, string strs[], int n)
{
    if (target.length() == 0)
    {
        return {{}};
    }

    for (int i = 0; i < n; i++)
    {
        if (isStartingSubset(target, strs[i]))
        {
            string rem = reduceTarget(target, strs[i]);
            vector<vector<string>> ans = canConstruct(rem, strs, n);
            if (ans[0][0] != "-1" || ans[0].size() != 0)
            {
                        }

            // ans[*index].push_back(strs[i]);
            return ans;
        }
    }
    return {{"-1"}};
}

int main()
{
    // map<string, bool> mem;

    vector<vector<string>> ans = {{}};
    int index = 0;

    string target = "skateboard";
    string strs[7] = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    ans = canConstruct(target, strs, 7);

    return 0;
}