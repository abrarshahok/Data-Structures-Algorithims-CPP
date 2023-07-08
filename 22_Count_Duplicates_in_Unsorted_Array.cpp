#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {8, 3, 6, 4, 5, 6, 8, 2, 7};
    int arr2[9] = {0};
    for (int i = 0; i < 10; i++)
    {
        arr2[arr[i]]++;
    }

    for (int i = 0; i < 9; i++)
    {
        if (arr2[i] > 1)
        {
            cout << i << " Apeared " << arr2[i] << " times." << endl;
        }
    }
}