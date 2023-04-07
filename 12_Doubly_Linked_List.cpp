#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node (int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head (node* &head, int val){
    node* newnode = new node(val);
    newnode->next = head;
    if (head!=NULL){
        head->prev = newnode;
    }
    head = newnode;
}

void insert_at_tail (node* &head, int val){
    node* newnode = new node(val);
    if (head == NULL){
        insert_at_head(head,val);
        return;
    }
    node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

void delete_at_head (node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void delete_node(node* &head, int key){
    if (head->data == key){
        delete_at_head(head);
        return;
    }
    node* temp = head;
    while (temp->next != NULL && temp->data != key){
        temp = temp->next;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void display (node* &head){
    node* temp = head;
    cout << "NULL -> ";
    while (temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

int main(){
    node* dll = NULL;
    insert_at_tail(dll,5);
    insert_at_tail(dll,4);
    insert_at_tail(dll,3);
    insert_at_head(dll,6);
    insert_at_head(dll,7);
    delete_node(dll,6);
    delete_at_head(dll);
    display(dll);
}