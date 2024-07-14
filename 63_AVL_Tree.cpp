#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    int height;

    Node(int data) : left(nullptr), right(nullptr), data(data), height(1) {}
};

class AVL {
private:
    int _nodeHeight(Node* node) {
        if (node == nullptr)
            return 0;
        int lh = node->left ? node->left->height : 0;
        int rh = node->right ? node->right->height : 0;
        return max(lh, rh) + 1;
    }

    int _balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        int lh = node->left ? node->left->height : 0;
        int rh = node->right ? node->right->height : 0;
        return lh - rh;
    }

    void _performLL(Node*& node) {
        Node* newNode = node->left;
        node->left = newNode->right;
        newNode->right = node;

        node->height = _nodeHeight(node);
        newNode->height = _nodeHeight(newNode);

        node = newNode;
    }

    void _performRR(Node*& node) {
        Node* newNode = node->right;
        node->right = newNode->left;
        newNode->left = node;

        node->height = _nodeHeight(node);
        newNode->height = _nodeHeight(newNode);

        node = newNode;
    }

    void _performLR(Node*& node) {
        _performRR(node->left);
        _performLL(node);
    }

    void _performRL(Node*& node) {
        _performLL(node->right);
        _performRR(node);
    }

    Node* _inPre(Node* node) {
        if (node == nullptr) return nullptr;
        node = node->left;
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* _inSucc(Node* node) {
        if (node == nullptr) return nullptr;
        node = node->right;
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void _performRotations(Node*& node) {
        int balance = _balanceFactor(node);

        if (balance > 1) {
            if (_balanceFactor(node->left) >= 0) {
                _performLL(node);
            }
            else {
                _performLR(node);
            }
        }
        else if (balance < -1) {
            if (_balanceFactor(node->right) <= 0) {
                _performRR(node);
            }
            else {
                _performRL(node);
            }
        }
    }

    void _insert(int data, Node*& node) {
        if (node == nullptr) {
            node = new Node(data);
            return;
        }

        if (data < node->data) {
            _insert(data, node->left);
        }
        else if (data > node->data) {
            _insert(data, node->right);
        }
        else {
            return;
        }

        node->height = _nodeHeight(node);

        _performRotations(node);
    }

    void _deleteNode(int key, Node*& node) {

        if (node == nullptr) return;

        if (!node->left && !node->right) {
            node = nullptr;
            delete node;
            return;
        }

        if (key < node->data) {
            _deleteNode(key, node->left);
        }
        else if (key > node->data) {
            _deleteNode(key, node->right);
        }
        else {
            if (_nodeHeight(node->left) > _nodeHeight(node->right))
            {
                Node* pre = _inPre(node);
                node->data = pre->data;
                _deleteNode(pre->data, node->left);
            }
            else {
                Node* succ = _inSucc(node);
                node->data = succ->data;
                _deleteNode(succ->data, node->right);
            }
        }

        if (node == nullptr) return;

        node->height = _nodeHeight(node);

        _performRotations(node);
    }

    void _inorderTraversal(Node*& node) {
        if (node != nullptr) {
            _inorderTraversal(node->left);
            cout << node->data << " ";
            _inorderTraversal(node->right);
        }
    }

    vector< vector<int> > _levelOrder(Node* node) {
        vector< vector<int> > res;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            int qLen = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < qLen; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr) {
                    currentLevel.push_back(curr->data);
                    if (curr->right) q.push(curr->right);
                    if (curr->left) q.push(curr->left);
                }
            }

            if (!currentLevel.empty()) {
                res.push_back(currentLevel);
            }
        }

        return res;
    }

    Node* _search(int key, Node*& node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key == node->data) {
            return node;
        }

        if (key < node->data) {
            return _search(key, node->left);
        }
        else {
            return _search(key, node->right);
        }

    }

    Node* _root;

public:
    AVL() :_root(nullptr) {}

    Node* getRoot() {
        return _root;
    }

    void insert(int data) {
        _insert(data, _root);
    }

    void deleteNode(int key) {
        _deleteNode(key, _root);
    }

    Node* search(int key) {
        return _search(key, _root);
    }

    void inorder() {
        _inorderTraversal(_root);
        cout << endl;
    }

    void levelOrder() {
        vector< vector<int> > res = _levelOrder(_root);

        for (int i = 0; i < res.size(); i++) {
            vector<int> data = res[i];
            for (int j = 0; j < data.size(); j++) {
                cout << data[j] << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    AVL tree = AVL();

    tree.insert(30);
    tree.insert(40);
    tree.insert(35);
    tree.insert(20);
    tree.insert(10);

    tree.inorder();
    tree.levelOrder();

    return 0;
}
