#include <iostream>
using namespace std;

// Write a Recursive Function to find Factorial of Number
int factorial_of_num(int n)
{
    if (n == 1)
        return 1;
    return factorial_of_num(n - 1) * n;
}

int main()
{
    int n = 5;
    int fact = factorial_of_num(n);
    cout << "Factorial of " << n << " is: " << fact << endl;
}