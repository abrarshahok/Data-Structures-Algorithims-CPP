#include <iostream>
#include <stack>
using namespace std;

stack <int> reverse (stack <int> &st){
    stack <int> rev;
    while (!st.empty()){
        rev.push(st.top());
        st.pop();
    }

    return rev;
}

void display(stack <int> &st){
    stack <int> temp = st;
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main(){
    stack <int> real;
    real.push(1);
    real.push(2);
    real.push(3);
    real.push(4);
    real.push(5);
    
    cout << "Before Reversing : ";
    display(real);

    stack <int> rev;
    rev = reverse(real);
    cout << "After Reversing  : ";
    display(rev);
}