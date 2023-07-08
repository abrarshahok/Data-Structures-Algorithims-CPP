#include <iostream>
#include <algorithm>
using namespace std;

// Write Recursive Function to Print Last Fibonacci Number in Seres using Memoization
int last_fib_memoization(int n)
{
    int F[n];
    fill(F, F + n, -1);

    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = last_fib_memoization(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = last_fib_memoization(n - 1);
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    int n = 10;
    cout << last_fib_memoization(n) << endl;
}