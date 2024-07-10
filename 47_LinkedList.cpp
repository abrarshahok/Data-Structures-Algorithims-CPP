#include <iostream>
#include <stack>
#include <vector>

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
        last = l1;
    }
    else {
        last = l2;
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

bool hasLoop(Node*& head) {
    Node* p1, * p2;

    p1 = p2 = head;

    do {
        p1 = p1->next;
        p2 = p2->next;
        p2 = p2 != nullptr ? p2->next : nullptr;
    } while (p1 && p2 && (p1 != p2));

    if (p1 == p2) {
        return true;
    }
    else {
        return false;
    }
}

Node* middleNode(Node*& head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* intersectingPoint(Node*& l1, Node*& l2) {
    std::stack<Node*> addressStackL1;
    std::stack<Node*> addressStackL2;

    Node* temp1 = l1;
    while (temp1 != nullptr) {
        addressStackL1.push(temp1);
        temp1 = temp1->next;
    }

    Node* temp2 = l2;
    while (temp2 != nullptr) {
        addressStackL2.push(temp2);
        temp2 = temp2->next;
    }

    Node* recentPoped;
    while (!addressStackL1.empty() && !addressStackL2.empty() && addressStackL1.top() == addressStackL2.top()) {
        recentPoped = addressStackL1.top();
        addressStackL1.pop();
        addressStackL2.pop();

    }

    return recentPoped;
}


Node* mergeKLists(std::vector<Node*>& lists) {
    if (lists.size() == 0) return nullptr;

    Node* first = lists[0];

    for (int i = 1; i < lists.size(); i++) {
        first = mergeListsR(first, lists[i]);
    }

    return first;
}

int main() {
    // // Creating the first list
    // Node* ll1 = nullptr;
    // insertAtTail(ll1, 2);
    // insertAtTail(ll1, 4);
    // insertAtTail(ll1, 6);
    // insertAtTail(ll1, 7);
    // insertAtTail(ll1, 8);
    // insertAtTail(ll1, 9);

    // // Creating the second list
    // Node* ll2 = nullptr;
    // insertAtTail(ll2, 1);
    // insertAtTail(ll2, 3);
    // insertAtTail(ll2, 5);

    // // Creating intersection (ll2 intersects with ll1 at node with value 11)
    // Node* temp1 = ll1;
    // while (temp1 && temp1->data != 7) {
    //     temp1 = temp1->next;
    // }

    // if (temp1) {
    //     Node* temp2 = ll2;
    //     while (temp2->next) {
    //         temp2 = temp2->next;
    //     }
    //     temp2->next = temp1;
    // }

    // display(ll1);
    // std::cout << std::endl;
    // display(ll2);
    // std::cout << std::endl;
    // Node* intersection = intersectingPoint(ll1, ll2);
    // if (intersection) {
    //     std::cout << "Intersection at node with value: " << intersection->data << std::endl;
    // }
    // else {
    //     std::cout << "No intersection" << std::endl;
    // }

    // std::cout << middleNode(ll1)->data;
    // Node* ll2 = nullptr;
    // insertAtTail(ll2, 4);
    // insertAtTail(ll2, 7);
    // insertAtTail(ll2, 12);
    // insertAtTail(ll2, 14);
    // // std::cout << countNodes(node) << std::endl;
    // // std::cout << sumOfNodes(node) << std::endl;
    // // std::cout << maxOfNodes(node) << std::endl;
    // // std::cout << minOfNodes(node) << std::endl;
    // // insertAtPosition(node, 5, 7);
    // // insertAtPosition(node, 0, 8);
    // // insertInSortedPosition(node, 3);
    // // insertInSortedPosition(node, 2);
    // // deleteNode(node, 2);
    // ll1 = mergeLists(ll1, ll2);
    // recursiveDisplay(ll1);
    // std::cout << isSorted(node) << std::endl;

    // // Forming a Loop in LL
    // Node* p1, * p2;

    // // Point p1 to 3rd Node
    // p1 = ll1->next->next;

    // // Point p2 to last Node
    // p2 = ll1->next->next->next;

    // // Point p2(last Node) to 3rd loop to Form a loop
    // p2->next = p1;

    // // Check for loop
    // std::cout << hasLoop(ll1);

    Node* ll1 = nullptr;
    insertAtTail(ll1, 1);
    insertAtTail(ll1, 2);
    insertAtTail(ll1, 3);
    insertAtTail(ll1, 4);
    insertAtTail(ll1, 5);
    insertAtTail(ll1, 6);
    display(ll1);
    // Node* ll2 = nullptr;
    // insertAtTail(ll2, 4);
    // insertAtTail(ll2, 5);
    // insertAtTail(ll2, 6);

    // Node* ll3 = nullptr;
    // insertAtTail(ll3, 8);
    // insertAtTail(ll3, 10);
    // insertAtTail(ll3, 12);

    // Node* ll4 = nullptr;
    // insertAtTail(ll4, 7);
    // insertAtTail(ll4, 9);
    // insertAtTail(ll4, 11);

    // std::vector<Node*> lists = { ll1, ll2, ll3, ll4 };
    // Node* finalList = mergeKLists(lists);
    // display(finalList);
}