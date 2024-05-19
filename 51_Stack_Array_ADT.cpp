#include <iostream>

class StackADT {
private:
    int size;
    int top;
    int* S;
public:
    StackADT(int size) {
        this->size = size;
        top = -1;
        S = new int[size];
    }
    void push(int x);
    int pop();
    int peek(int index);
    int stackTop();
    bool isEmpty();
    bool isFull();
    void display();
};

void StackADT::push(int x) {
    if (top == size - 1) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    S[top++] = x;
}

int StackADT::pop() {
    if (top == -1) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;
    }

    return S[top--];
}

int StackADT::peek(int index) {
    return (index >= size) ? -1 : S[index];
}

int StackADT::stackTop() {
    return (top == -1) ? -1 : S[top];
}

bool StackADT::isEmpty() {
    return top == -1;
}

bool StackADT::isFull() {
    return top == size - 1;
}

void StackADT::display() {
    for (int i = 0; i <= top; i++) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    StackADT stack = StackADT(5);
    std::cout << stack.isEmpty() << std::endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.isFull() << std::endl;
    stack.push(4);
    stack.push(5);
    std::cout << stack.isFull() << std::endl;
    std::cout << stack.stackTop() << std::endl;
    std::cout << stack.peek(4) << std::endl;
    stack.display();
}