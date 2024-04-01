#include <iostream>
using namespace std;

// Write a Recursive Function to find Power of Number in Less Calls
int power_of_num_reduced(int m, int n)
{
    if (n <= 0)
        return 1;

    if (n % 2 == 0)
        return power_of_num_reduced(m * m, n / 2);
    else
        return power_of_num_reduced(m * m, (n - 1) / 2) * m;
}

int main()
{
    int base = 2;
    int pow = 5;
    int power = power_of_num_reduced(base, pow);
    cout << base << "^" << pow << " = " << power << endl;
}