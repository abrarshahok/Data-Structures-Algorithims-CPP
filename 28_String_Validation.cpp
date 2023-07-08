#include <iostream>
#include <string>
using namespace std;

bool passValidation(const char* password){
    bool valid = false;
    for(int i = 0; password[i] != '\0'; i++){
        if((password[i] >=65 && password[i]<=90) 
        || ((password[i]>=97 &&password[i]<=122)) 
        ||((password[i] >=48 && password[i] <=57))){
            valid = true;
        }
    }
    return valid;
}

int main(){
    const char *password = "aBc1234";
    string result = passValidation(password) ? "Valid Pass" : "Invalid Pass";
    cout << result<<endl;

}