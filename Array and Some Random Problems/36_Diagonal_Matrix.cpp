#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A = NULL;
    int n;

public:
    void create(int size)
    {
        this->n = size;
        A = new int[n];
    }

    void set(int i, int j, int x)
    {
        if (i == j)
            A[i] = x;
    }

    int get(int i, int j)
    {
        if (i == j)
            return A[i];
        else
            return 0;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << A[i] << "\t";
                else
                    cout << 0 << "\t";
            }
            cout << endl;
        }
    }
    int *operator+(Matrix A2)
    {

        for (int i = 0; i < n; i++)
        {
            A[i] = get(i, i) + A2.get(i, i);
        }
        return A;
    }
    ~Matrix()
    {

        A = NULL;
        delete A;
    }
};

int main()
{
    Matrix diagonal1;
    Matrix diagonal2;
    diagonal1.create(5);
    diagonal2.create(5);
    diagonal1.set(0, 0, 4);
    diagonal1.set(1, 1, 5);
    diagonal1.set(2, 2, 6);
    diagonal1.set(3, 3, 7);
    diagonal1.set(4, 4, 8);
    diagonal2.set(0, 0, 4);
    diagonal2.set(1, 1, 5);
    diagonal2.set(2, 2, 6);
    diagonal2.set(3, 3, 7);
    diagonal2.set(4, 4, 8);
    diagonal1 + diagonal2;
    diagonal1.display();
}