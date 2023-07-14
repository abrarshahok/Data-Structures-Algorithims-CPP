#include <iostream>
using namespace std;
int n = 5;

bool isSymetric(int arr[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int matrix[5][5] = {
        {2, 2, 2, 2, 2},
        {2, 3, 3, 3, 3},
        {2, 3, 4, 4, 4},
        {2, 3, 4, 5, 5},
        {2, 3, 4, 5, 6},
    };

    isSymetric(matrix) ? cout << "Symetric Matrix" << endl : cout << "Not Symetric Matrix" << endl;
}