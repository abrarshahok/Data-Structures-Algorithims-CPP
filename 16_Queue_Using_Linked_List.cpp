#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

class queue{
    private:
    node*  front;
    node* rear;

    public:
    queue(){
        front = NULL;
        rear  = NULL;
    }

    void enqueue(int val){
        node* newnode = new node(val);
        if (front == NULL){
            front = newnode;
            rear  = newnode;
            return;
        }

        rear->next = newnode;
        rear = newnode;
    }

    void dequeue(){
        if (front == NULL){
            cout << "Queue Underflow"<<endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        cout << "Deleted -> "<<todelete->data << endl;
        delete todelete;
    }

    int peek(){
        if (front != NULL){
            return front->data;
        }
        return -1;
    }

    void display(){
        node* temp = front;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    queue q1;
    q1.enqueue(5);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(3);
    cout << "Peek -> " << q1.peek() << endl;
    q1.display();
    q1.dequeue();
    q1.display();
    cout << "Peek -> " << q1.peek() << endl;
}