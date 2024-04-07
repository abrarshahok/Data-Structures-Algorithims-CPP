#include <iostream>
#include <string>
using namespace std;

string toUppercase(string lowerCase)
{
    string upperCase = "";
    for (int i = 0; i < lowerCase.length(); i++)
    {
        if (lowerCase[i] >= 65 || lowerCase[i] <= 90)
        {
            upperCase += lowerCase[i] - 32;
        }
    }
    return upperCase;
}

string toLowerCase(string upperCase)
{
    string lowerCase = "";
    for (int i = 0; i < upperCase.length(); i++)
    {
        if (upperCase[i] >= 97 || upperCase[i] <= 122)
        {
            lowerCase += upperCase[i] + 32;
        }
    }
    return lowerCase;
}

int main()
{
    string orgStr = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = toUppercase(orgStr);
    cout << uppercase << endl;

    string lowerCase = toLowerCase(uppercase);
    cout << lowerCase << endl;
}