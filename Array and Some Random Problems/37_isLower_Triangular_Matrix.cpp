#include <iostream>
using namespace std;

int n = 5;

bool isLowerTrinagular(int arr[][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[n][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
    };

    isLowerTrinagular(arr) ? cout << "Yes, it is lower tringular matrix" << endl : cout << "No, it is not lower tringular matrix" << endl;
}