#include <iostream>
using namespace std;

int main()
{
    int key = 10;
    int arr[10] = {20, 4, 6, 7, 3, 8, 2, 9, 1, -10};
    // Method 1 O(n2);
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = i + 1; j < 10; j++)
    //     {
    //         if (arr[i] + arr[j] == key)
    //         {
    //             cout << "(" << arr[i] << ") + (" << arr[j] << ") = " << key << endl;
    //         }
    //     }
    // }

    // Method 2 using Hashing O(n)
    int H[11] = {0};

    for (int i = 0; i < 11; i++)
    {
        H[arr[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (H[key - arr[i]] != 0)
        {
            cout << "(" << arr[i] << ") + (" << key - arr[i] << ") = " << key << endl;
        }
        H[arr[i]]++;
    }
}