#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    // int dup = 0;

    // for (int i = 0; i < 10; i++)
    // {
    //     if (arr[i] == arr[i + 1])
    //     {
    //         dup = i + 1;
    //         while (arr[dup] == arr[i])
    //         {
    //             dup++;
    //         }
    //         cout << arr[i] << " is appearing " << dup - i << " times" << endl;
    //         i = dup - 1;
    //     }
    // }

    // Method 2
    int H[20] = {0};
    int lastDup = 0;
    for (int i = 0; i < 10; i++)
    {
        while (arr[i] == arr[i + 1] || arr[i] == lastDup)
        {
            lastDup = arr[i];
            H[arr[i]]++;
            i++;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        if (H[i] != 0)
        {
            cout << i << " Appeared " << H[i] << " times" << endl;
        }
    }
}