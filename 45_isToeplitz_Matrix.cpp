#include <iostream>
using namespace std;

bool isToeplitz(int arr[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i + 1 < 5 && j + 1 < 5) && (arr[i][j] != arr[i + 1][j + 1]))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 1, 2, 3, 4},
        {7, 6, 1, 2, 3},
        {8, 7, 6, 1, 2},
        {9, 8, 7, 6, 1},
    };

    if (isToeplitz(arr))
    {
        cout << "Toeplitz Array" << endl;
    }
    else
    {
        cout << "Not Toeplitz Array" << endl;
    }
}
