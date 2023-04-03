#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        this->data=val;
        this->next=NULL;
    }
};

void insert (node* &head, int val){
    node* newnode = new node(val);
    if (head == NULL){
        head = newnode;
        newnode->next = head;
        return;
    }

    node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void insert_at_head (node* &head, int val){
    node* newnode = new node(val);
    if (head == NULL){
        head = newnode;
        newnode->next = head;
        return;
    }

    node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

void delete_at_head (node* &head){
    node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }

    temp->next = head->next;
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void delete_node (node* &head, int key){
    node* prev_ptr = NULL;
    node* curr_ptr = head;
    if (head->data == key){
        delete_at_head(head);
        return;
    }

    while (curr_ptr->next != head){
        if (curr_ptr->data == key){
            break;
        }
        prev_ptr = curr_ptr;
        curr_ptr = curr_ptr->next;
    }    

    if (curr_ptr->next != head && curr_ptr->data != key){
        return;
    }

    prev_ptr->next = curr_ptr->next;
    delete curr_ptr;
}

void reverse(node* &head) {
    if (head == NULL || head->next == NULL){
        return;
    }

    node* curr = head;
    node* prev = NULL;
    node* nextP = NULL;

    do{
        nextP = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextP;
    }while (curr != head);

    head->next = prev;
    head = prev;
}


void display (node* &head){
    node* temp = head;
    if (head == NULL){
        return;
    }
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while (temp != head);

    cout << "head(" << head->data << ")"<<endl;
}

int main (){
    node* list = NULL;
    insert(list,1);
    insert(list,2);
    insert(list,3);
    // delete_node(list,3);
    reverse(list);
    // insert_at_head(list,5);
    // delete_at_head(list);
    insert(list,5);
    display(list);
}