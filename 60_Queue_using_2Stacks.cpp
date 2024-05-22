#include <iostream>
#include "52_Stack_LL_ADT.cpp"

class Queue {
public:
    StackLLADT<int> st1;
    StackLLADT<int> st2;

    void enqueue(int x) {
        st1.push(x);
    }

    int dequeue() {
        if (st1.isEmpty() && st2.isEmpty()) return-1;

        if (st2.isEmpty()) {
            while (!st1.isEmpty()) {
                st2.push(st1.pop());
            }
        }

        return st2.pop();
    }

    void display() {
        if (st1.isEmpty() && st2.isEmpty()) return;

        while (!st1.isEmpty()) {
            st2.push(st1.pop());
        }

        st2.display();
    }

};

int main() {
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.display();
}