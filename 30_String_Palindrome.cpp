#include <iostream>
#include <algorithm>
using namespace std;

string reverse(string str){
    transform(str.begin(), str.end(), str.begin() ,::tolower);
    for(int i=0, j=str.length()-1; i<str.length()/2; i++,j--){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

int main(){
    string orgStr = "madam";
    string reversed = reverse(orgStr);
    if(orgStr == reversed){
        cout << "String is Palindrome" << endl;
    }
    else{
        cout << "String is not Palindrome" << endl;
    }
}