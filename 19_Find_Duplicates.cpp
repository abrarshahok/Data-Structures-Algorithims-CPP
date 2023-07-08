#include <iostream>
using namespace std;

int main()
{
    // Method 1
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int lastDuplicate = 0;
    // cout << "Duplicates: ";
    // for (int i = 0; i < 10; i++)
    // {
    //     if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
    //     {
    //         cout << arr[i] << " ";
    //         lastDuplicate = arr[i];
    //     }
    // }

    int arr2[20] = {0};
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
        {
            arr2[arr[i]] = 1;
            lastDuplicate = arr[i];
        }
    }

    cout << "Duplicates: ";
    for (int i = 1; i < 20; i++)
    {
        if (arr2[i] != 0)
        {
            cout << i << " ";
        }
    }
}