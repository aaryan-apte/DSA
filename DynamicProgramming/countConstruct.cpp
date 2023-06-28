#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isStartingSubset(string target, string str)
{
    if (target.length() >= str.length())
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
        result += target[i];

    return result;
}

int canConstruct(string target, string strs[], int n, map<string, int> mem)
{
    auto it = mem.find(target);
    if (it != mem.end())
        return mem[target];

    if (target.length() == 0)
        return 1;

    int totalCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (isStartingSubset(target, strs[i]))
        {
            string rem = reduceTarget(target, strs[i]);

            totalCount += canConstruct(rem, strs, n, mem);
            // if (canConstruct(rem, strs, n, mem))
            // {
            //     mem[rem] = ;
            //     return true;
            // }
        }
    }
    mem[target] = totalCount;
    return totalCount;
}

int main()
{
    map<string, int> mem;

    string target = "skateboard";
    string strs[7] = {"bo", "rd", "ate", "t", "ska", "sk", "obar"};
    cout << canConstruct(target, strs, 7, mem);

    return 0;
}