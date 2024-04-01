#include <iostream>
using namespace std;
int main()
{
    int arr[11] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};

    int diff = arr[0];

    cout << "Missing Elements: ";
    for (int i = 0; i < 11; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                cout << diff + i << " ";
                diff++;
            }
        }
    }
}