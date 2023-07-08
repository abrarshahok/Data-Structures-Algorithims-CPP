#include <iostream>
using namespace std;

// Write Recursive Function for evaluating nCr
int nCr(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// Write Iterative Function for evaluating nCr

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int nCr_iter(int n, int r)
{

    int num = fact(n);
    int den = fact(r) * fact(n - r);
    return (num / den);
}

int main()
{
    int n = 6;
    int r = 2;
    int nCr_rec = nCr(n, r);
    int nCr_it = nCr_iter(n, r);
    cout << nCr_rec << endl
         << nCr_it << endl;
}