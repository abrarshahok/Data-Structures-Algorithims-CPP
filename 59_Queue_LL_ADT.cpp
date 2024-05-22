#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) :data(data), next(nullptr) {}
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() :front(nullptr), rear(nullptr) {}

    bool isFull() {
        Node* n = new Node(0);
        return n == nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue Full" << std::endl;
            return;
        }

        Node* newNode = new Node(x);

        if (front == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Empty" << std::endl;
            return;
        }

        Node* toDelete = front;
        front = front->next;
        delete toDelete;
    }

    void display() {
        Node* temp = front;

        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << std::endl;

    }
};

int main() {
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
}