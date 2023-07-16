#include <iostream>
#include <vector>
using namespace std;

string removeOccurrences(string s, string part)
{
    // hare krishna!
    string newString = "";
    int i = 0;
    while (i < s.length())
    {
        if (s[i] != part[0])
        {
            newString += s[i];
            i++;
            continue;
        }
        else if (s[i] == part[0])
        {
            int count = 0, pos = i, posPart = 0;
            while (posPart < part.length() && pos < s.length() && s[pos] == part[posPart])
            {
                count++;
                pos++;
                posPart++;
            }
            if (count == part.length())
            {
                i += part.length();
                continue;
            }
            else
            {
                cout << "Hare Krishna\n";
                newString += s[i];
                i++;
                continue;
            }
        }
        i++;
    }
    cout << endl
         << "New string has length: \n"
         << newString.length() << endl;
    return newString;
}

int main()
{
    string s = "daabcbaabcbc";
    cout << removeOccurrences(s, "abc");

    return 0;
}