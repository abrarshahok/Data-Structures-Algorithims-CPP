#include <iostream>
using namespace std;

int main()
{
    // If sequence of First n Natural Numbers then use formula n(n+1)/2
    // int arr[11] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    // int sumN = 12 * (12 + 1) / 2;
    // int sumArray = 0;
    // for (int i = 0; i < 11; i++)
    // {
    //     sumArray += arr[i];
    // }

    // int missingNum = sumN - sumArray;
    // if (missingNum != 0)
    // {
    //     cout << "Missing Number is: " << missingNum << endl;
    // }
    // else
    // {
    //     cout << "No Missing Number" << endl;
    // }

    // If no sequence of First n Natural Numbers Method 1
    // int arr[11] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};

    // int first = arr[0];
    // int last = arr[10];

    // int sumN = last * (last + 1) / 2;
    // int sumMissing = (first - 1) * (first) / 2;

    // int finalSum = sumN - sumMissing;
    // int sumArray = 0;

    // for (int i = 0; i < 11; i++)
    // {
    //     sumArray += arr[i];
    // }

    // cout << finalSum - sumArray;

    // If no sequence of First n Natural Numbers Method 2
    int arr[11] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    int first = arr[0];
    int diff = first;
    int n = 11;
    int missingNum;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            missingNum = diff + i;
            break;
        }
    }

    cout << missingNum;
}