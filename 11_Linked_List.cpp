#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void insert_at_tail (node* &head, int val){
    node* newNode = new node(val);

    if (head == NULL){
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void insert_at_head (node* &head, int val){
    node* newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

bool search_node (node* &head, int key){
    node* temp = head;
    if (head == NULL){
        cout << "Can't Search in Empty List!"<<endl;
        return false;
    }

    while (temp->next != NULL){
        if (temp->data == key){
            cout << "Key -> "<<key<<" -> Found" <<endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Key -> "<<key<<" -> Not Found!" <<endl;
    return false;
}

void delete_at_head (node* &head){
    if (head == NULL){
        cout << "Can't Delete in Empty List!"<<endl;
        return;
    }
    node* temp = head;
    head = temp->next;
    cout << "Deleted -> "<<temp->data<<endl;
    delete temp;
}

void delete_node (node* &head, int key){

    if (head == NULL){
        cout << "Can't Delete in Empty List!"<<endl;
        return;
    }

    if (head->next == NULL){
        delete_at_head(head);
        return;
    }
    node* temp = head;
    while (temp->next->data != key){
        temp = temp->next;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted -> "<<toDelete->data<<endl;
    delete toDelete;
}

node* reverse (node* &head){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;

    while (currPtr!=NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    // Returning PrevPtr because it is new Head of Linked List
    return prevPtr;
}

node* recurse_Reverse (node* &head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = recurse_Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

node* reverseK (node* &head, int k){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;
    int count = 0;
    while (currPtr != NULL && count < k){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
        
        count++;
    }

    if (nextPtr != NULL){
        head->next = reverseK(nextPtr,k);
    }

    return prevPtr;
}

void display (node* &head){
    node* temp = head;
    if (head == NULL){
        cout << "List is Empty" << endl;
        return;
    }

    while (temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    system("clear");
    node* head = NULL;
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_head(head,4);
    insert_at_head(head,3);
    insert_at_head(head,2);
    // search_node(head,7);
    // delete_at_head(head);
    // delete_node(head,6);
    // delete_at_head(head);
    // delete_at_head(head);
    cout << "Before Reversing : ";
    display(head);
    // node* newList = reverse(head);
    // node* newListRecursive = recurse_Reverse(head);
    int k = 2;
    node* newListK = reverseK(head,k);
    cout << "After Reversing "<< k <<" Nodes : ";
    display(newListK);
}