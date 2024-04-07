#include <iostream>
using namespace std;

int main()
{
    string str = "finding";
    int H = 0;
    int x = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        x = 1;
        x = x << (str[i] - 97);
        // Bit Masking
        if ((x & H) > 0)
        {
            cout << str[i] << " is Duplicate" << endl;
        }
        else
        {
            // Bit Merging
            H = x | H;
        }
    }
}