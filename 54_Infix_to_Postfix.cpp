#include <iostream>
#include "52_Stack_LL_ADT.cpp"

bool isOperator(char ch) {
    return (ch == '/' || ch == '*' || ch == '-' || ch == '+' || ch == '^');
}

int precedence(char opt) {
    if (opt == '+' || opt == '-') return 1;

    else if (opt == '*' || opt == '/') return 2;

    else if (opt == '^') return 3;

    return 0;
}

std::string infixToPostix(std::string str) {
    StackLLADT<char> st;
    std::string postfix = "";

    int len = str.length();

    for (int i = 0; i < len; i++) {

        // If is alphabet or number push it
        if (isalnum(str[i])) {
            postfix += str[i];
        }

        // If is opening bracket "(" simply push it
        else if (str[i] == '(') {
            st.push(str[i]);
        }

        // When encounter closing bracket ")"
        // Enter stack elements to PostFix string until stack is empty
        // or encounters opening bracket "("
        else if (str[i] == ')') {
            while (!st.isEmpty() && st.stackTop() != '(') {
                postfix += st.stackTop();
                st.pop();
            }

            // After adding all stack elements except '('
            // Check for opening bracket "(" and pop it
            if (!st.isEmpty() && st.stackTop() == '(') {
                st.pop();
            }
        }

        // If is operator
        // Check precedence of current and new opt 
        // if precedence of top opt is greater than or equal to current opt then add to postfix and pop
        // until stack is empty or precedence of top opt is less then current opt
        else if (isOperator(str[i])) {
            while (!st.isEmpty() && precedence(st.stackTop()) >= precedence(str[i])) {
                postfix += st.stackTop();
                st.pop();
            }

            // After simply push new operator
            st.push(str[i]);
        }
    }

    // At last check for remaing opts in stack and add to Postfix
    while (!st.isEmpty()) {
        postfix += st.stackTop();
        st.pop();
    }

    return postfix;
}

// int main() {
//     std::string str = "K+L-M*N+(O^P)*W/U/V*T+Q";
//     std::string postfix = infixToPostix(str);
//     std::cout << postfix << std::endl;
// }