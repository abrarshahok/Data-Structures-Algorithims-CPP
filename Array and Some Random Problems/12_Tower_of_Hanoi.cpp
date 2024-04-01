#include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "Tower [" << A << "] to Tower [" << C << "]" << endl;
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    int disks;
    cout << "Enter Number of Disks to Move from Tower A to C : ";
    cin >> disks;
    cout << "Follow these steps to move all Disks from Tower A to C" << endl;
    TOH(disks, 1, 2, 3);
}