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

void display(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

void recursiveDisplay(Node*& head) {
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

void insertAtPosition(Node*& head, int position, int data) {

    int numberOfNodes = countNodes(head);

    if (position < 0 || position > numberOfNodes) {
        std::cout << "Invalid Position";
        return;
    }

    Node* newNode = new Node(data);

    if (position == 0 || head == nullptr) {
        insertAtHead(head, data);
        return;
    }

    if (position == numberOfNodes) {
        insertAtTail(head, data);
        return;
    }

    Node* temp = head;

    int count = 0;

    while (temp->next != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (!temp->next) {
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertInSortedPosition(Node*& head, int data) {

    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    if (head->data >= data) {
        insertAtHead(head, data);
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr->data < data && curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == nullptr) {
        insertAtTail(head, data);
    }
    else {
        newNode->next = curr;
        prev->next = newNode;
    }
}

void deleteAtHead(Node*& head) {
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteNode(Node*& head, int key) {
    if (head == nullptr) {
        return;
    }

    if (head->data == key) {
        deleteAtHead(head);
        return;
    }


    // // Approach 1
    // Node* curr = head;
    // Node* prev = nullptr;

    // while (curr->data != key) {
    //     prev = curr;
    //     curr = curr->next;
    // }

    // if (curr->next == nullptr) {
    //     return;
    // }

    // Node* toDelete = curr;
    // prev->next = curr->next;
    // delete toDelete;

    // Approach 2
    Node* temp = head;

    while (temp->next->data != key) {
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

}

bool isSortedRecursive(Node*& head) {
    static int x = INT32_MIN;

    if (head == nullptr) {
        return true;
    }

    if (x < head->data) {
        x = head->data;
        return isSortedRecursive(head->next);
    }

    return false;
}

bool isSorted(Node*& head) {
    if (head == nullptr) {
        return true;
    }

    int x = INT32_MIN;

    while (head != nullptr) {
        if (head->data < x) return false;
        x = head->data;
        head = head->next;
    }

    return true;
}


void removeDuplicates(Node*& head) {
    if (head == nullptr) {
        return;
    }

    // Approach 1
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            Node* todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
        }
        else {
            temp = temp->next;
        }
    }


}

void reverseLL(Node*& head) {
    if (head == nullptr) {
        return;
    }

    Node* prevPtr = nullptr;
    Node* currPtr = head;
    Node* nextPtr;

    while (currPtr != nullptr) {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    head = prevPtr;
}

Node* reverseLLR(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* newhead = reverseLLR(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}

Node* concatenateLists(Node*& l1, Node*& l2) {
    Node* temp = l1;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = l2;
    l2 = nullptr;
    return l1;
}

Node* mergeLists(Node*& l1, Node*& l2) {
    Node* third;
    Node* last;

    if (l1->data < l2->data) {
        third = last = l1;
        l1 = l1->next;
        last->next = nullptr;
    }
    else {
        third = last = l2;
        l2 = l2->next;
        last->next = nullptr;
    }

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            last->next = l1;
            last = l1;
            l1 = l1->next;
            last->next = nullptr;
        }
        else {
            last->next = l2;
            last = l2;
            l2 = l2->next;
            last->next = nullptr;
        }
    }

    if (l1 != nullptr) {
        last->next = l1;
    }
    else {
        last->next = l2;

    }

    return third;
}

Node* mergeListsR(Node*& l1, Node*& l2) {
    if (l1 == nullptr) {
        return l2;
    }
    else if (l2 == nullptr) {
        return l1;
    }
    else if (l1->data < l2->data) {
        l1->next = mergeListsR(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeListsR(l1, l2->next);
        return l2;
    }
}

int main() {
    Node* ll1 = nullptr;
    insertAtTail(ll1, 2);
    insertAtTail(ll1, 8);
    insertAtTail(ll1, 10);
    insertAtTail(ll1, 15);

    Node* ll2 = nullptr;
    insertAtTail(ll2, 4);
    insertAtTail(ll2, 7);
    insertAtTail(ll2, 12);
    insertAtTail(ll2, 14);
    // std::cout << countNodes(node) << std::endl;
    // std::cout << sumOfNodes(node) << std::endl;
    // std::cout << maxOfNodes(node) << std::endl;
    // std::cout << minOfNodes(node) << std::endl;
    // insertAtPosition(node, 5, 7);
    // insertAtPosition(node, 0, 8);
    // insertInSortedPosition(node, 3);
    // insertInSortedPosition(node, 2);
    // deleteNode(node, 2);
    ll1 = mergeLists(ll1, ll2);
    recursiveDisplay(ll1);
    // std::cout << isSorted(node) << std::endl;

}