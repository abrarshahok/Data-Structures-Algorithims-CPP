#include <iostream>
using namespace std;

int row = 3;

bool isDiagonal(int arr[][3])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i != j && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[row][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    };
    string result = isDiagonal(arr) ? "True" : "False";
    cout << result << endl;
}