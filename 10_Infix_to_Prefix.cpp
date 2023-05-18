#include <iostream>
#include <stack>
#include <algorithm>
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

bool isOperator(char op)
{
    if (op == '^' || op == '*' || op == '/' || op == '+' || op == '-')
        return true;
    else
        return false;
}

void closing_bracket_to_opening(string &exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp.at(i) == '(')
        {
            exp.at(i) = ')';
        }
        else if (exp.at(i) == ')')
        {
            exp.at(i) = ')';
        }
    }
}

string infix_to_prefix(string infix)
{

    reverse(infix.begin(), infix.end());
    closing_bracket_to_opening(infix);
    stack<char> st;
    string prefix = "";
    for (int i = 0; i < infix.length(); i++)
    {

        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            prefix += infix[i];
        }

        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                prefix += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }

        else if (isOperator(infix[i]))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(infix[i]))
            {
                prefix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix, prefix;
    cout << "Enter Infix Exp : ";
    getline(cin, infix);
    prefix = infix_to_prefix(infix);
    cout << "Prefix : " << prefix << endl;
}