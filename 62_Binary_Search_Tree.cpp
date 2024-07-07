#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) :left(nullptr), right(nullptr), data(data) {}
};

class BST {
public:
    void insert(int data, Node*& root) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        if (root->data == data) {
            return;
        }

        if (data < root->data) {
            insert(data, root->left);
        }
        else {
            insert(data, root->right);
        }
    }

    bool search(int key, Node*& root) {

        if (root == nullptr) {
            return false;
        }

        if (root->data == key) {
            return true;
        }

        if (key < root->data) {
            return search(key, root->left);
        }
        else {
            return search(key, root->right);
        }
    }

    void deleteNode(int key, Node*& root) {

        if (root == nullptr) return;

        if (!(root->left && root->right)) {
            root = nullptr;
            delete(root);
            return;
        }

        if (key < root->data) {
            deleteNode(key, root->left);
        }
        else if (key > root->data) {
            deleteNode(key, root->right);
        }
        else {
            if (height(root->left) > height(root->right))
            {
                Node* pre = inPre(root->left);
                root->data = pre->data;
                deleteNode(pre->data, root->left);
            }
            else {
                Node* succ = inSucc(root->right);
                root->data = succ->data;
                deleteNode(succ->data, root->right);
            }
        }

    }

    int height(Node* p) {
        int x;
        int y;
        if (p == nullptr) {
            return 0;
        }
        x = height(p->left);
        y = height(p->right);
        return x > y ? x + 1 : y + 1;
    }

    Node* inPre(Node* p) {
        while (p && p->right != nullptr) {
            p = p->left;
        }
        return p;
    }

    Node* inSucc(Node* p) {
        while (p && p->left != nullptr) {
            p = p->right;
        }
        return p;
    }


    void BSTFromPreOrder(int pre[], int n, Node*& root) {
        if (n == 0) return;

        root = new Node(pre[0]);

        Node* temp = nullptr;

        stack<Node*> st;

        st.push(root);

        for (int i = 1; i < n; i++) {
            if (pre[i] < st.top()->data) {
                temp = new Node(pre[i]);
                st.top()->left = temp;
                st.push(temp);
            }
            else {
                while (!st.empty() && pre[i] > st.top()->data) {
                    temp = st.top();
                    st.pop();
                }

                temp->right = new Node(pre[i]);
                st.push(temp->right);
            }
        }
    }

    void BSTFromPostOrder(int post[], int n, Node*& root) {
        if (n == 0) return;

        root = new Node(post[n - 1]);

        Node* temp = nullptr;

        stack<Node*> st;

        st.push(root);

        for (int i = n - 2; i >= 0; i--) {
            if (post[i] < st.top()->data) {
                temp = new Node(post[i]);
                st.top()->left = temp;
                st.push(temp);
            }
            else {
                while (!st.empty() && post[i] > st.top()->data) {
                    temp = st.top();
                    st.pop();
                }

                temp->right = new Node(post[i]);
                st.push(temp->right);
            }
        }
    }

    void inorder(Node*& root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node*& root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node*& root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};


int main() {

    Node* root = nullptr;
    BST tree = BST();

    // tree.insert(30, root);
    // tree.insert(20, root);
    // tree.insert(10, root);
    // tree.insert(50, root);
    // tree.insert(40, root);
    // tree.insert(60, root);


    // tree.inorder(root);

    // tree.deleteNode(50, root);

    // cout << endl;

    // tree.inorder(root);
    // int pre[8] = { 30,20,10,15,25,40,50,45 };
    // tree.BSTFromPreOrder(pre, 8, root);
    // tree.preorder(root);

    int post[8] = { 45,50,40,25,15,10,20,30 };
    tree.BSTFromPostOrder(post, 8, root);
    tree.postorder(root);

    return 0;
}