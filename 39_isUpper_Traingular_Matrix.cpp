#include <iostream>
using namespace std;

int n = 5;

bool isUpperTrinagular(int arr[][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && arr[i][j] != 0)
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
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
    };

    isUpperTrinagular(arr) ? cout << "Yes, it is upper tringular matrix" << endl : cout << "No, it is not upper tringular matrix" << endl;
}