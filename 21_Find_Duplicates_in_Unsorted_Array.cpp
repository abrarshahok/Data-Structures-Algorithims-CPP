#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {8, 3, 6, 4, 5, 6, 8, 2, 7};
    int count;
    for (int i = 0; i < 9; i++)
    {
        count = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < 10; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if (count > 1)
        {
            cout << arr[i] << " appeared " << count << " times." << endl;
        }
    }
}