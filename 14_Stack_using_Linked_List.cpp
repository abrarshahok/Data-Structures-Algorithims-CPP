#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        this->data=val;
        this->next=NULL;
    }
};

class stack{
    private:
    node* top;

    public:

    stack(){
        this->top = NULL;
    }

    bool isEmpty(){
        return (top == NULL);
    }

    int peek(int pos){
        node* temp = top;
        for (int i=1; i<pos; i++){
            temp = temp->next;
        }
        if (temp != NULL){
            return temp->data;
        }
        return -1;
    }

    void push (int val){
        node* newnode = new node(val);
        // Pointing Newnode next to Top
        newnode->next = top;

        // Putting New value in Top
        top = newnode;
    }

    void pop (){
        if (isEmpty()){
            cout << "Stack Underflow!" <<endl;
            return;
        }

        node* temp = top;
        top = top->next;

        cout << "Poped -> " << temp->data << endl;
        delete temp;
    }

    void print(){
        node* temp = top;
        while (temp != NULL){
            cout << "[" << temp->data << "]" << endl;
            temp = temp->next;
        }
    }
};  

int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // st.pop();
    // st.pop();
    // for (int i=1; i<=4; i++){
    //     cout << "Element at Position " << i << " : "<<st.peek(i) <<endl;
    // }
    st.print();
}