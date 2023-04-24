#include <iostream>
#include <vector>
using namespace std;

bool checkEqual(int count1[26], int count2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}

string removeDuplicates(string s)
{
    int i = 0;
    cout << s.length() << endl;
    while (i < s.length() - 1)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, i + 2);
            // s.erase(s.begin() + i);
            // s.erase(s.begin() + i + 1);
            cout << s << endl;
            i = -1;
            cout << s.length() << endl;
        }

        i++;
    }
    return s;
}

int main()
{
    string s1 = "Hanuman Ram";
    cin >> s1;
    cout << removeDuplicates(s1);
    // s1.erase(0, 2);
    // cout << s1;
    // string s1, s2;
    // cout << "Enter the main string:\n";
    // cin >> s2;
    // cout << "Enter the substring:\n";
    // cin >> s1;

    // int count1[26];

    // // Ikde, count kelet substring chya letters che occurences.

    // for (int i = 0; i < s1.length(); i++)
    // {
    //     int index = s1[i] - 'a';
    //     count1[index]++;
    // }

    // int windowSize = s1.length();
    // int count2[26] = {0};

    // int i = 0;
    // while (i < s2.length() && i < windowSize)
    // {
    //     int index = s2[i] - 'a';
    //     count2[index]++;
    //     i++;
    // }

    // if (checkEqual(count1, count2))
    // {
    //     cout << "Yes\n";
    //     exit(898);
    // }

    // while (i < s2.length())
    // {
    //     char newChar = s2[i];
    //     int index = s2[i] - 'a';
    //     count2[index]++;
    //     char oldChar = s2[i - windowSize];
    //     int oldIndex = oldChar - 'a';
    //     count2[oldIndex]--;
    //     i++;
    //     if (checkEqual(count1, count2))
    //     {
    //         cout << "yes\n";
    //         exit(898);
    //     }
    // }
    // cout << "no\n";
    // exit(3);

    return 0;
}