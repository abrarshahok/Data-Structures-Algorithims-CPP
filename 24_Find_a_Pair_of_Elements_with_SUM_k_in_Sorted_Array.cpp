#include <iostream>
using namespace std;

int main()
{
    int key = 10;
    int arr[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int i = 0;
    int j = 9;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == key)
        {
            cout << "(" << arr[i] << ") + (" << arr[j] << ") = " << key << endl;
            i++;
            j--;
        }
        else if (sum < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}