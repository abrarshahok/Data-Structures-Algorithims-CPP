#include <iostream>
using namespace std;

// Write a Recursive Function for Taylor Series using Honers Rule
double taylor_series_honers_rule(int x, int n)
{
    static double result;
    if (n == 0)
        return result;

    result = 1 + (x * result) / n;
    return taylor_series_honers_rule(x, n - 1);
}

int main()
{
    double eX_Honers_Rule = taylor_series_honers_rule(1, 10);
    cout << eX_Honers_Rule << endl;
}