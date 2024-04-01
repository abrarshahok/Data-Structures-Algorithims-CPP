#include <iostream>
using namespace std;

bool checkAngram(string s1, string s2)
{

    if (s1.length() != s2.length())
    {
        return false;
    }

    int H[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        H[s1[i] - 97]++;
        H[s2[i] - 97]--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "decimal";
    string str2 = "medical";

    string result = checkAngram(str1, str2) ? "Strings are Anagram" : "Strings are not Anagram";
    cout << result << endl;
}