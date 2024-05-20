#include <iostream>


template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) :data(data), next(nullptr) {}

};

template <typename T>
class StackLLADT {
    Node<T>* top;
public:

    StackLLADT() :top(nullptr) {}

    ~StackLLADT() {
        top = nullptr;
        delete top;
    }

    void push(T x) {
        Node<T>* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        Node<T>* temp = top;
        top = top->next;
        int poppedData = temp->data;
        delete temp;
        return poppedData;
    }

    T peek(int index) {
        Node<T>* temp = top;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr) return -1;
            temp = temp->next;
        }
        return temp == nullptr ? -1 : temp->data;
    }

    T stackTop() {
        return isEmpty() ? -1 : top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        Node<T>* node = new Node(0);
        // Node creation failed
        return node == nullptr;
    }

    void display() {
        Node<T>* temp = top;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};




// int main() {
//     StackLLADT<int> st;
//     std::cout << st.isEmpty() << std::endl;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     std::cout << st.isEmpty() << std::endl;
//     st.push(4);
//     st.push(5);
//     st.display();
//     std::cout << st.stackTop() << std::endl;
//     std::cout << st.isFull() << std::endl;
//     std::cout << st.peek(4) << std::endl;
// }