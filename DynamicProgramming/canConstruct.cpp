#include <iostream>
#include <string>
// #include <map>
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
    }
    return true;
}

string reduceTarget(string target, string str)
{
    // aahet subset...
    string result = "";

    for (int i = str.length(); i < target.length(); i++)
        result.push_back(target[i]);

    return result;
}

bool canConstruct(string target, string strs[], int n)
{
    if (target.length() == 0)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (isStartingSubset(target, strs[i]))
        {
            string rem = reduceTarget(target, strs[i]);
            if (canConstruct(rem, strs, n))
                return true;
        }
    }
    return false;
}

int main()
{
    // map<string, bool> mem;

    string target = "skateboard";
    string strs[7] = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    cout << canConstruct(target, strs, 7);

    return 0;
}