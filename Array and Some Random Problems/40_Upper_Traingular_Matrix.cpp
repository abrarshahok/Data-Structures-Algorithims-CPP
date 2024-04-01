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
        A = new int[n * (n + 1) / 2];
    }

    void set(int i, int j, int x)
    {
        if (i <= j)
        {
            A[j * (j + 1) / 2 + i] = x; // Column Major Formula
            // A[j * (i + 1) / 2 + j] = x; // Row Major Formula
        }
    }
    int get(int i, int j)
    {
        if (i <= j)
        {
            return A[j * (j + 1) / 2 + i]; // Column Major Formula
            // return A[j * (i + 1) / 2 + j]; // Row Major Formula
        }
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

    ~Matrix()
    {
        A = NULL;
        delete A;
    }
};
int main()
{
    Matrix upper_triangular;
    upper_triangular.create(3);
    upper_triangular.set(0, 0, 1);
    upper_triangular.set(0, 1, 2);
    upper_triangular.set(0, 2, 3);
    upper_triangular.set(1, 1, 4);
    upper_triangular.set(1, 2, 5);
    upper_triangular.set(2, 2, 6);
    upper_triangular.display();
}