#include <iostream>
using namespace std;

// Write Recursive Function to Print Fibonacci Series
int fibonnaci_series(int first, int second, int last)
{
    if (first == 0 && second == 1)
    {
        cout << first << " " << second << " ";
    }

    if (last == 1)
    {
        return 0;
    }

    int sum = first + second;
    cout << sum << " ";
    return fibonnaci_series(second, sum, last - 1);
}

int main()
{
    int f = 0;
    int s = 1;
    int l = 10;
    fibonnaci_series(f, s, l);
    cout << endl;
}