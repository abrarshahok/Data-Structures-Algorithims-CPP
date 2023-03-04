#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperator (char op)
{
    if (op == '^' || op == '*' || op == '/' || op == '+' || op == '-')
        return true;
    else
        return false;
}

bool isOperand (char op)
{
    if( op >= 'a' && op <= 'z' || op >= 'A' && op <= 'Z' || op >='0' && op <='9')
        return true;
    else
        return false;
}

string InfixToPostfix (stack <char> st, string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if (isOperand(infix[i])) 
        {
            postfix += infix[i];
        } 
        
        else if (infix[i] == '(') 
        {
            st.push(infix[i]);
        } 
        
        else if (infix[i] == ')') 
        {
            while (st.top() != '(') 
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop the opening bracket
        } 

        else if (isOperator(infix[i])) 
        {
            while (!st.empty() && st.top() != '(' && precedence(infix[i]) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix,postfix,prefix;
    stack <char> Stack;
    cout<<"Enter Infix Exp : ";
    getline(cin,infix);

    postfix = InfixToPostfix(Stack,infix);
    cout<<"Postfix : "<<postfix<<endl;

    for(int i = postfix.length() - 1; i>=0 ; i--)
        prefix+=postfix.at(i);

    cout<<"Prefix  : "<<prefix<<endl;
}