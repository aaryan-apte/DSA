#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(string a)
{
    string s = "";
    char c;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (('9' >= a[i] && a[i] >= '0') || ('Z' >= a[i] && a[i] >= 'A') ||
            ('z' >= a[i] && a[i] >= 'a'))
        {
            if ('A' <= a[i] && 'Z' >= a[i])
            {
                char c = (char)((int)a[i] + 97 - 65);
                s = s + c;
            }
            else
            {
                s = s + a[i];
            }
        }
    }
    int l = 0;
    int h = s.length() - 1;
    int count = 0;

    cout << s << endl;
    while (l < h)
    {
        if (s[l] == s[h])
        {
            // cout << endl
            //  << s[l] << " " << s[h] << endl;
            count++;
        }
        l++;
        h--;
    }

    if (count == s.length() / 2)
    {
        cout << "Yes\n";
        return true;
    }
    cout << "No\n";
    return false;
}

int main()
{
    string s = "Hare @!$*&!!!!@#$@!()";
    cout << checkPalindrome(s);

    return 0;
}
