#include <iostream>
#include "52_Stack_LL_ADT.cpp"

bool isBalanced(std::string str) {
    StackLLADT<char> st;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            st.push(str[i]);
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {

            if (st.isEmpty()) return false;

            if ((st.stackTop() == '{' && str[i] == '}')
                || (st.stackTop() == '[' && str[i] == ']')
                || (st.stackTop() == '(' && str[i] == ')')) {

                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.isEmpty();
}

int main() {
    std::string str = "{[(a+b+(c+d)*e)+f]*g}";
    std::cout << (isBalanced(str) ? "true" : "false") << std::endl;
}