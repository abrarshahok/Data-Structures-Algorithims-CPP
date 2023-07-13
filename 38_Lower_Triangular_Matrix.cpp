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
        if (i >= j)
        {

            // A[n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)] = x; // Column Major Formula
            A[i * (i + 1) / 2 + j] = x; // Row Major Formula
        }
    }
    int get(int i, int j)
    {
        if (i >= j)
        {
            // return A[n * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)]; // Column Major Formula
            return A[i * (i + 1) / 2 + j]; // Row Major Formula
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
                if (i >= j)
                {
                    cout << get(i, j) << "\t";
                }
                else
                {
                    cout << 0 << "\t";
                }
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
    Matrix lower_triangular;
    lower_triangular.create(3);
    lower_triangular.set(0, 0, 1);
    lower_triangular.set(1, 0, 2);
    lower_triangular.set(1, 1, 3);
    lower_triangular.set(2, 0, 4);
    lower_triangular.set(2, 1, 5);
    lower_triangular.set(2, 2, 6);
    lower_triangular.display();
}