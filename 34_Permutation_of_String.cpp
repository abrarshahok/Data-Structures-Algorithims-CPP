#include <iostream>
using namespace std;

void Permutation(string str, int k)
{
    static int flagArray[10] = {0};
    static char resultArray[10] = {0};

    if (str[k] == '\0')
    {
        resultArray[k] = '\0';
        cout << resultArray << endl;
    }
    else
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (flagArray[i] == 0)
            {
                flagArray[i] = 1;
                resultArray[k] = str[i];
                Permutation(str, k + 1);
                flagArray[i] = 0;
            }
        }
    }
}

int main()
{
    string str = "ABCD";
    Permutation(str, 0);
}