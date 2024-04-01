#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtTail(Node*& head, int data) {
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
}

void display(Node*& head)
{
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void recursiveDisplay(Node*& head)
{
    Node* temp = head;
    if (temp == nullptr) {
        return;
    }
    std::cout << temp->data << " ";
    recursiveDisplay(temp->next);
}

int countNodes(Node*& head) {
    if (head == nullptr) {
        return 0;
    }
    return countNodes(head->next) + 1;
}

int sumOfNodes(Node*& head) {
    if (head == nullptr) {
        return 0;
    }

    return sumOfNodes(head->next) + head->data;
}

int maxOfNodes(Node*& head) {
    if (head == nullptr) {
        return INT32_MIN;
    }

    return (head->data < maxOfNodes(head->next)) ? maxOfNodes(head->next) : head->data;

}

int minOfNodes(Node*& head) {
    if (head == nullptr) {
        return INT32_MAX;
    }

    return (head->data > minOfNodes(head->next)) ? minOfNodes(head->next) : head->data;

}

Node* search(Node*& head, int key) {
    if (head == nullptr) {
        return nullptr;
    }

    return head->data == key ? head : search(head->next, key);
}

void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

Node* improvedSearch(Node*& head, int key) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return nullptr;
    }

    prev->next = curr->next;
    curr->next = head;
    head = curr;
    return head;
}



int main() {
    Node* node = nullptr;

    for (int i = 1; i <= 5; i++) {
        insertAtTail(node, i);
    }

    recursiveDisplay(node);
    std::cout << std::endl;
    // std::cout << countNodes(node) << std::endl;
    // std::cout << sumOfNodes(node) << std::endl;
    // std::cout << maxOfNodes(node) << std::endl;
    // std::cout << minOfNodes(node) << std::endl;
    std::cout << improvedSearch(node, 4);
    std::cout << std::endl;
    recursiveDisplay(node);
    std::cout << std::endl;

}