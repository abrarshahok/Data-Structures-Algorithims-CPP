#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node() {}
    Node(int data) :data(data), next(nullptr) {}
};

class StackLLADT {
    Node* top;
public:
    StackLLADT() :top(nullptr) {}
    void push(int x);
    int pop();
    int peek(int index);
    int stackTop();
    bool isEmpty();
    bool isFull();
    void display();
};

void StackLLADT::push(int x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
}

int StackLLADT::pop() {
    Node* temp = top;
    top = top->next;
    int poppedData = temp->data;
    delete temp;
    return poppedData;
}

int StackLLADT::peek(int index) {
    Node* temp = top;
    for (int i = 0; i < index; i++) {
        if (temp == nullptr) return -1;
        temp = temp->next;
    }
    return temp == nullptr ? -1 : temp->data;
}

int StackLLADT::stackTop() {
    return isEmpty() ? -1 : top->data;
}

bool StackLLADT::isEmpty() {
    return top == nullptr;
}

bool StackLLADT::isFull() {
    Node* node = new Node();
    // Node creation failed
    return node == nullptr;
}

void StackLLADT::display() {
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    StackLLADT st;
    std::cout << st.isEmpty() << std::endl;
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout << st.isEmpty() << std::endl;
    st.push(4);
    st.push(5);
    st.display();
    std::cout << st.stackTop() << std::endl;
    std::cout << st.isFull() << std::endl;
    std::cout << st.peek(4) << std::endl;
}