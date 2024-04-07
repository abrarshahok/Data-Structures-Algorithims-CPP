#include <iostream>
using namespace std;

int main()
{
    // Method 1 for Declaring and Intializing (Whole Array is inside stack)
    // int arr[3][4] = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    // };

    // Method 2 for Declaring and Intializing
    // int *p = new int[3]; // not right method
    // int *p[3]; // Array of Pointer p is inside stack but actual array is inside heap
    // p[0] = new int[4];
    // p[1] = new int[4];
    // p[2] = new int[4];

    // p[0][1] = 10;
    // cout << p[0][1] << endl;

    // Method 3 for Declaring and Intializing (to declare everything in heap we can use double pointers)
    int **P = new int *[3]; // Array of 3 Pointers is Created inside heap
    P[0] = new int[4];
    P[1] = new int[4];
    P[2] = new int[4];

    // Lets initialze this array with values
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            P[i][j] = i + j + 1;
        }
    }

    // Lets Access Elements of  this array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }
}