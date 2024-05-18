#include <iostream>
using namespace std;

class Matrix
{
private:
    int* A;
    int n;

public:
    void create(int n)
    {
        this->n = n;
        A = new int[n + n - 1];
    }

    void set(int i, int j, int x)
    {
        if (i <= j)
            A[(i - j) + (n - 1)] = x;
        else
            A[(j - i)] = x;
    }

    int get(int i, int j)
    {
        if (i <= j)
            return A[(i - j) + (n - 1)];
        else
            return A[(j - i)];
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix toeplitz;
    toeplitz.create(5);
    toeplitz.set(0, 0, 1);
    toeplitz.set(0, 1, 2);
    toeplitz.set(0, 2, 3);
    toeplitz.set(0, 3, 4);
    toeplitz.set(0, 4, 5);
    toeplitz.set(1, 0, 6);
    toeplitz.set(2, 0, 7);
    toeplitz.set(3, 0, 8);
    toeplitz.set(4, 0, 9);
    toeplitz.display();

    return 0;
}
