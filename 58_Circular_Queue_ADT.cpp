#include <iostream>

class CircularQueue {
public:
    int size;
    int front;
    int rear;
    int* Q;

    CircularQueue(int size) {
        this->size = size;
        front = rear = 0;
        this->Q = new int[size];
    }

    void enqueue(int x) {
        if ((rear + 1) % size == front) {
            std::cout << "Queue Full" << std::endl;
        }
        else {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }

    void dequeue() {
        if (front == rear) {
            std::cout << "Queue Empty" << std::endl;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void display() {
        int i = front + 1;

        do {
            std::cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);

        std::cout << std::endl;
    }

};

int main() {
    CircularQueue q = CircularQueue(6);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
}
