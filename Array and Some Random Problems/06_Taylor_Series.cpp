#include <iostream>
using namespace std;

// Write a Recursive Function for Taylor Series
double taylor_rec(int x, int n)
{
    static double fact = 1.0, power = 1.0;
    double result;
    if (n == 0)
        return 1;
    else
    {
        result = taylor_rec(x, n - 1);
        power *= x;
        fact *= n;
        return result + (power / fact);
    }
}

// Write a Iterative Function for Taylor Series
double taylor_iter(int x, int n)
{
    double fact = 1.0, power = 1.0;
    double result = 1.0;

    for (int i = 1; i <= n; i++)
    {
        power *= x;
        fact *= i;
        result += (power / fact);
    }
    return result;
}

int main()
{
    double eX_Rec = taylor_rec(1, 10);
    double eX_Iter = taylor_iter(1, 10);
    cout << eX_Rec << endl
         << eX_Iter << endl;
}