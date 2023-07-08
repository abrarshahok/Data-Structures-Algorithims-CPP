#include <iostream>
using namespace std;

// Write a Recursive Function to find sum of First N Natural Numbers
int sum_n_natural_nums(int n)
{
    if (n == 0)
        return 0;
    return sum_n_natural_nums(n - 1) + n;
}

int main()
{
    int n = 10;
    int sum = sum_n_natural_nums(10);
    cout << "Sum of First " << n << " Natural Numbers: " << sum << endl;
}