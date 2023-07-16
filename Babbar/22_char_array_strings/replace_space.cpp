#include <iostream>
#include <vector>
using namespace std;

string replaceSpaces(string &s)
{
    int i = 0;
    string s1 = "";
    int j = 0;
    while (s[i] != '\0')
    {
        if ((int)s[i] != 32)
        {
            s1 = s1 + s[i];
        }
        else
        {
            s1 = s1 + '@';
            s1 = s1 + '4';
            s1 = s1 + '0';
        }
        i++;
    }
    // cout << s1;
    return s1;
}

int main()
{
    string s = "Jai Shree Ram!";
    cout << replaceSpaces(s);

    return 0;
}