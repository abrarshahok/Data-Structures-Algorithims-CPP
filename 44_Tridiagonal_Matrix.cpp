#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A = NULL;
    int n;

public:
    void create(int n)
    {
        this->n = n;
        A = new int[(3 * n) - 2];
    }

    void set(int i, int j, int x)
    {
        if (i - j == 0 || i - j == 1 || i - j == -1)
            A[(2 * j) + i - 1] = x;
    }

    int get(int i, int j)
    {
        if (i - j == 0 || i - j == 1 || i - j == -1)
            return A[(2 * j) + i - 1];
        else
            return 0;
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
    Matrix tridiagonal;
    tridiagonal.create(5);
    tridiagonal.set(0, 0, 1);
    tridiagonal.set(1, 1, 1);
    tridiagonal.set(2, 2, 1);
    tridiagonal.set(3, 3, 1);
    tridiagonal.set(4, 4, 1);
    tridiagonal.set(0, 1, 2);
    tridiagonal.set(1, 2, 2);
    tridiagonal.set(2, 3, 2);
    tridiagonal.set(3, 4, 2);
    tridiagonal.set(1, 0, 2);
    tridiagonal.set(2, 1, 2);
    tridiagonal.set(3, 2, 2);
    tridiagonal.set(4, 3, 2);
    tridiagonal.display();
}