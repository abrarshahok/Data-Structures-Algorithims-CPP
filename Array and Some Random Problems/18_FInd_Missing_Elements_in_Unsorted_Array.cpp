#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int arr2[12] = {0};

    for (int i = 0; i < 10; i++)
    {
        arr2[arr[i]] = 1;
    }

    cout << "Missing Elements: ";
    for (int i = 1; i <= 12; i++)
    {
        if (arr2[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}