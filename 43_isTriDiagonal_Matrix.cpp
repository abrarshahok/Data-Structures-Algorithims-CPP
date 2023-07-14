#include <iostream>
using namespace std;

const int n = 5;

bool isTridiagonal(int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i - j > 1 || j - i > 1) && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int matrix[n][n] = {
        {1, 1, 0, 0, 0},
        {1, 2, 2, 0, 0},
        {0, 2, 3, 3, 0},
        {0, 0, 3, 4, 4},
        {0, 0, 0, 4, 5},
    };

    isTridiagonal(matrix) ? cout << "Tridiagonal Matrix" << endl : cout << "Not Tridiagonal Matrix" << endl;
}
