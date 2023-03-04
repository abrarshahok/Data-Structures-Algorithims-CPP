#include <iostream>
using namespace std;

class stack{
    private:
        int size;
        int top;
        int* ptr;

    public:
        stack(int size){
            this->size = size;
            this->top  = -1;
            this->ptr  = new int[size];
        }

        bool isFull(stack *s){
            if(s->top == s->size-1){
                cout<<"Stack Overflow!"<<endl;
                return true;
            }
            return false;
        }

        bool isEmpty(stack *s){
            if(s->top == -1){
                cout << "Stack Empty!"<<endl;
                return true;
            }
            return false;
        }

        void push(stack *s, int item){
            if(!s->isFull(s)){
                s->top++;
                s->ptr[top] = item;
                cout << "Pushed -> "<<item<<endl;
            }
        }

        void peek(stack *s){
            if(!isEmpty(s)){
                cout << "Top Element -> "<<s->ptr[top]<<endl;
            }
        }

        void bottom(stack *s){
            if(!isEmpty(s)){
                cout << "Bottom Element -> "<<s->ptr[0]<<endl;
            }
        }
        void pop(stack *s){
            if(!s->isEmpty(s)){
                cout << "Poped -> "<<s->ptr[top]<<endl;
                s->top--;
            }
        }

        void display_stack(stack *s){
            cout << "Stack Elements -> ";
            for(int i=0; i<=s->top; i++){
                cout<<s->ptr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    system("clear");
    stack st(5);
    st.pop(&st);
    st.push(&st,5);
    st.push(&st,6);
    st.push(&st,7);
    st.push(&st,8);
    st.push(&st,9);
    st.display_stack(&st);
    st.pop(&st);
    st.push(&st,10);
    st.display_stack(&st);
    st.push(&st,11);
    st.peek(&st);
    st.pop(&st);
    st.peek(&st);
    st.bottom(&st);
}