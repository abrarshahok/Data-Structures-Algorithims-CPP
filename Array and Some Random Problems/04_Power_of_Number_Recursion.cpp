#include <iostream>
using namespace std;

// Write a Recursive Function to find Power of Number
int power_of_num(int m, int n)
{
    if (n == 0)
        return 1;
    return power_of_num(m, n - 1) * m;
}

int main()
{
    int base = 2;
    int pow = 5;
    int power = power_of_num(base, pow);
    cout << base << "^" << pow << " = " << power << endl;
}