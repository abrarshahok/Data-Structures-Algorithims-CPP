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
        if (i >= 0 && i < n || j >= 0 && j < n)
        {
            if (i >= j)
                A[i * (j + 1) / 2 + j] = x;
            else
                A[j * (i + 1) / 2 + i] = x;
        }
    }

    int get(int i, int j)
    {
        if (i >= 0 && i < n || j >= 0 && j < n)
        {
            if (i >= j)
                return A[i * (j + 1) / 2 + j];
            else
                return A[j * (i + 1) / 2 + i];
        }
        return 0;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= j)
                    cout << get(i, j) << " ";
                else
                    cout << get(j, i) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix symetric_matrix;
    symetric_matrix.create(3);
    symetric_matrix.set(0, 0, 2);
    symetric_matrix.set(0, 1, 2);
    symetric_matrix.set(0, 2, 2);
    symetric_matrix.set(1, 1, 3);
    symetric_matrix.set(1, 2, 3);
    symetric_matrix.set(2, 2, 4);
    symetric_matrix.display();
}