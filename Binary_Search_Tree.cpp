#include <iostream>
using namespace std;

class node{
    public:
    int key;
    node* left;
    node* right;

    node (int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:
    node* root;

    BST(){
        this->root = NULL;
    }

    void insertion (int key){
        node* newNode = new node(key);

        if (root == NULL){
            root = newNode;
            return;
        }

        node* current = root;

        while (true){
            if (key < current->key){
                if (current->left == NULL){
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }

            else if (key > current->key){
                if (current->right == NULL){
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }

            else{
                cout << key <<"Already Exists"<<endl;
                return;
            }
        }
    }

    void traverse_preorder (node* &Node){
        if (Node == NULL){
            return;
        }
        // Formula :- NLR
        cout << Node->key << " ";
        traverse_preorder(Node->left);
        traverse_preorder(Node->right);
    }

    void traverse_Inorder (node* &Node){
        if (Node == NULL){
            return;
        }

        // Formula :- LNR
        traverse_Inorder(Node->left);
        cout << Node->key << " ";
        traverse_Inorder(Node->right);
    }

    void traverse_postorder (node* &Node){
        if (Node == NULL){
            return;
        }

        // Formula :- LRN
        traverse_postorder(Node->left);
        traverse_postorder(Node->right);
        cout << Node->key << " ";
    }

    void printTraversals (){
        cout << "Preorder Traversal  : ";
        traverse_preorder(root);
        cout << "\nInorder Traversal   : ";
        traverse_Inorder(root);
        cout << "\nPostorder Traversal : ";
        traverse_postorder(root);
        cout << endl;
    }
};

int main(){
    BST tree;
    tree.insertion(10);
    tree.insertion(30);
    tree.insertion(20);
    tree.insertion(40);
    tree.insertion(50);
    tree.printTraversals();
}