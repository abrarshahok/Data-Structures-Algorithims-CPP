#include <iostream>
#include <string>
using namespace std;

bool isVowel(char check)
{
    if (check == 'a' || check == 'A' || check == 'e' || check == 'E' 
    || check == 'i' || check == 'I' || check == 'o' || check == 'O' 
    || check == 'u' || check == 'U'){
        return true;
    }
    return false;
}

int main(){
    string sentence = "How are you";
    int vowels = 0;
    int consonants = 0;
    int words = 1;
    for (int i = 0; i < sentence.length(); i++){

        if (isVowel(sentence[i])){
            vowels++;
        }

        else if ((sentence[i] >= 65 && sentence[i] <= 90) 
            || (sentence[i] >= 97 && sentence[i] <= 122)){
            consonants++;
        }

        if (sentence[i] == ' ' && sentence[i-1] != ' '){
            words++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Words: " << words << endl;
}