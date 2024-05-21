#include <istream>
#include "54_Infix_to_Postfix.cpp"


int calc(char opt, int first, int second) {
    if (opt == '/') {
        return second / first;
    }
    else if (opt == '*') {
        return second * first;
    }
    else if (opt == '-') {
        return second - first;
    }
    else {
        return second + first;
    }
}

int evaluate(std::string s) {

    StackLLADT<int> st;

    s = infixToPostix(s);

    for (int i = 0; i < s.length(); i++) {
        if (isOperator(s[i])) {
            int first = st.pop();
            int second = st.pop();
            int ans = calc(s[i], first, second);
            st.push(ans);
        }
        else {
            int value = s[i] - '0';
            st.push(value);
        }
    }

    return st.pop();
}

int main() {
    std::string str = "3*5+6/2-4";
    int eval = evaluate(str);
    std::cout << eval << std::endl;
}