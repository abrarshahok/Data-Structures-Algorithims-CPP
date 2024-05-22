#include <iostream>

class Queue {
public:
    int size;
    int front;
    int rear;
    int* Q;

    Queue(int size) {
        this->size = size;
        front = rear = -1;
        this->Q = new int[size];
    }

    void enqueue(int x) {
        if (rear == size - 1) {
            std::cout << "Queue Full" << std::endl;
            return;
        }

        if (front == -1 && rear == -1) {
            front = rear = 0;
            Q[rear] = x;
        }
        else {
            rear++;
            Q[rear] = x;
        }
    }

    void dequeue() {
        if (front > rear) {
            std::cout << "Queue Empty" << std::endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    void display() {
        if (rear == -1 && front == -1) return;

        for (int i = front; i <= rear; i++) {
            std::cout << Q[i] << " ";
        }

        std::cout << std::endl;
    }

};

int main() {
    Queue q = Queue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();
}
