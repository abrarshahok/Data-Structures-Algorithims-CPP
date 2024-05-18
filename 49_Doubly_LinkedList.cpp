#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}

};

int length(Node*& head) {
    return (head->next) ? length(head->next) + 1 : 0;
}


void insertAtTailDLL(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}



void insertAtHeadDLL(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtIndexDLL(Node*& head, int data, int index) {

    if (index == 0) {
        insertAtHeadDLL(head, data);
        return;
    }

    if (index >= length(head)) {
        insertAtTailDLL(head, data);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < index - 1; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteAtHeadDLL(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;

    delete temp;

    if (head != nullptr) {
        head->prev = nullptr;
    }
}

void deleteAtIndexDLL(Node*& head, int index) {
    if (head == nullptr) return;

    if (index == 0) return deleteAtHeadDLL(head);

    Node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        if (temp == nullptr) return;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete toDelete;
}

Node* reverseDLL(Node*& head) {
    if (head == nullptr) return nullptr;

    Node* current = head;
    Node* temp;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
    return head;
}



void createDLL(Node*& head, int n, int values[]) {
    for (int i = 0; i < n; i++) {
        insertAtTailDLL(head, values[i]);
    }
}

void printDLL(Node*& head) {
    if (head == nullptr) return;

    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


int main() {
    Node* DLL = nullptr;
    int n = 5;
    int values[n] = { 1, 7, 4, 6, 8 };
    createDLL(DLL, n, values);
    // insertAtHeadDLL(DLL, 2);
    // insertAtIndexDLL(DLL, 9, 0);
    // deleteAtHeadDLL(DLL);
    // deleteAtIndexDLL(DLL, 2);
    DLL = reverseDLL(DLL);
    printDLL(DLL);
}