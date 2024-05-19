#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}

};

void insertAtTailCDLL(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
}


void insertAtHeadCDLL(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else {
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;

        head = newNode;
    }
}

void createCDLL(Node*& head, int n, int values[]) {
    for (int i = 0; i < n; i++) {
        insertAtTailCDLL(head, values[i]);
    }
}

void printCDLL(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

int main() {
    Node* CDLL = nullptr;
    int n = 5;
    int values[n] = { 1, 7, 4, 6, 8 };
    createCDLL(CDLL, n, values);
    printCDLL(CDLL);
}