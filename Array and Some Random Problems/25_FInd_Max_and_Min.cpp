#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {3, 1, 5, 2, 10, 15, 8, 9, 20, 4};
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        else if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << "Max: " << max << "\nMin: " << min << endl;
}