#include <iostream>
using namespace std;

// Write Recursive Function to Print Last Fibonacci Number in Series
int last_fib(int n)
{
    if (n <= 1)
        return n;
    return last_fib(n - 2) + last_fib(n - 1);
}

// Write Iterative Function to Print Last Fibonacci Number in Series
int last_fib_iter(int n)
{
    int first = 0, second = 1;
    int last;
    for (int i = 2; i <= n; i++)
    {
        last = first + second;
        first = second;
        second = last;
    }
    return last;
}

int main()
{
    int n = 10;
    cout << last_fib(n) << endl;
    cout << last_fib_iter(n) << endl;
}