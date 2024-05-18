#include<iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void deleteAtHead(Node*& head) {
    if (head == nullptr) return;
    Node* toDelete = head;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    head = head->next;
    temp->next = head;

    delete toDelete;
}

void deleteNodeCLL(Node*& head, int key) {
    if (head == nullptr) return;

    if (head->data == key) {
        deleteAtHead(head);
        return;
    };

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != key) {
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void createCLL(Node*& head, int n) {
    for (int i = 1; i <= n; i++) {
        insertAtTail(head, i);
    }
}

void printCLL(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;

    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

}

void printCLLR(Node* head, Node*& temp) {
    static int flag = 0;
    if (temp != head || flag == 0) {
        flag = 1;
        std::cout << temp->data << " ";
        printCLLR(head, temp->next);
    }
    flag = 0;
}

int main() {
    Node* CLL = nullptr;
    createCLL(CLL, 5);
    deleteNodeCLL(CLL, 1);
    deleteNodeCLL(CLL, 3);
    printCLLR(CLL, CLL);

    return 0;
}
