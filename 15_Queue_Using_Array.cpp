#include <iostream>
using namespace std;

class queue{
    private:
    int* queue_arr;
    int front;
    int back;
    int size;

    public:

    queue (int s){
        this->size = s;
        front = -1;
        back  = -1;
        queue_arr = new int [size];
    }

    void enqueue (int element){
        if(front == -1){
            front++;
        }
        if (back == size - 1){
            cout << "Queue Overflow!"<<endl;
            return;
        }
        back++;
        queue_arr[back] = element;
    }

    void dequeue (){
        if (front == -1 || front > back){
            cout << "Queue Underflow!" << endl;
            return;
        }
        front++;
    }

    int peek (){
        if (front == -1 || front > back){
            return -1;
        }
        return (queue_arr[front]);
    }

    bool isEmpty (){
        if (front == -1 || front > back){
            return true;
        }
        return false;
    }

    void display (){
        if(!isEmpty()){
            cout << "Queue Elememts : ";
            for (int i=front; i<=back; i++){
            cout << queue_arr[i] << " ";
        }
            cout << endl;
            return;
        }
        cout << "Queue Empty !" << endl;
    }
};

int main (){
    system ("clear");
    queue* q = new queue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    cout << "Peek -> "<< q->peek()<<endl;
    q->display();
    q->dequeue();
    cout << "Peek -> "<< q->peek()<<endl;
    q->display();
    q->dequeue();
    cout << "Peek -> "<< q->peek()<<endl;
    q->display();
    q->dequeue();
    cout << "Peek -> "<< q->peek()<<endl;
    q->display();
}