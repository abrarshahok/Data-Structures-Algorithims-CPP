#include <iostream>
using namespace std;

string reverse(string str){
    for(int i=0, j=str.length()-1; i<str.length()/2; i++,j--){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

int main(){
    string orgStr = "jalwa";
    cout << reverse(orgStr) << endl;
}