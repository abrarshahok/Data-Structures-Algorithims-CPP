#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    node (int data){
        this->data  = data;
        this->right = NULL;
        this->left  = NULL;
    }

    void traverse_preorder (node* temp){
        if (temp != NULL){
            cout << temp->data << " ";
            traverse_preorder(temp->left);
            traverse_preorder(temp->right);
        }
    }

    void traverse_inorder (node* temp){
        if (temp != NULL){
            traverse_inorder (temp->left);
            cout << temp->data << " ";
            traverse_inorder (temp->right);
        }
    }

    void traverse_postorder (node* temp){
        if (temp != NULL){
            traverse_postorder(temp->left);
            traverse_postorder(temp->right);
            cout << temp->data << " ";
        }
    }
};

int main (){
    node* newNode  = new node(1);
    newNode->right = new node(2);
    newNode->left  = new node(3);
    newNode->left->left = new node(4);
    newNode->left->right = new node(5);

    node* temp;
    cout << "Preorder  : ";
    temp->traverse_preorder(newNode);
    cout << endl;
    cout << "Inorder   : ";
    temp->traverse_inorder(newNode);
    cout << endl;
    cout << "Postorder : ";
    temp->traverse_postorder(newNode);
    cout << endl;
    
    /* 
        1
       / \
     2    3  
        /  \
       4    5

    */
}