#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "finding";

    // Method 1 Time O(n2) Space O(str.length)
    // cout << "Duplicates: ";
    // for(int i=0; i<str.length(); i++){
    //     for(int j=i+1; j<str.length(); j++){
    //         if(str[j] != 0){
    //             if(str[i] == str[j]){
    //                 cout << str[i] << " ";
    //                 str[j]=0;
    //             }
    //         }
    //     }
    // }

    // Method 2 Using Hashing Time O(n) Space O(25)
    int hashMap[26] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        hashMap[str[i] - 97]++;
    }

    for (int i = 1; i < 26; i++)
    {
        if (hashMap[i] > 1)
        {
            cout << char(i + 97) << " appeared " << hashMap[i] << " times" << endl;
        }
    }

    cout << endl;
}