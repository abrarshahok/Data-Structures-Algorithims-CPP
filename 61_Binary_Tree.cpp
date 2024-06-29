// Binary Tree => Collection of nodes where each node has a left pointer, right pointer and a data element
// Height of a binary tree => Number of edges in the longest path from the root to a leaf node
// Depth of a node => Number of edges in the path from the root to the node
// Level of a node => Depth of the node + 1
// Height of a node => Number of edges in the longest path from the node to a leaf node
// Descendant of a node => All the nodes that can be reached by traversing the node
// Ancestor of a node => All the nodes that can be reached by traversing the root node
// Sibling of a node => Nodes that share the same parent
// Internal node => Node with at least one child
// Leaf node => Node with no children
// Height of a binary tree with 1 node = 0
// Height of an empty binary tree = -1
// Height of a binary tree with n nodes = n-1
// Number of nodes in a binary tree with height h = 2^(h+1) - 1
// Number of leaf nodes in a binary tree = Number of nodes with 0 children
// Number of nodes with 2 children in a binary tree = Number of internal nodes
// Number of nodes with 1 child in a binary tree = Number of internal nodes
// Number of leaf nodes in a binary tree with height h = 2^h
// Number of internal nodes in a binary tree with height h = 2^h - 1
// Number of nodes in a binary tree with n leaf nodes = 2n - 1
// Number of nodes in a binary tree with n internal nodes = 2n
// Number of nodes in a binary tree with n leaf nodes and h height = n + 2^h - 1
// Number of nodes in a binary tree with n internal nodes and h height = n + 2^h
// Maximum height of a binary tree with n nodes = n - 1 (In the case of a linear structure, i.e., every node has only one child except the leaf node)
// Minimum height of a binary tree with n nodes = floor(log2(n)) (In the case of a complete binary tree)
// Maximum number of nodes in a binary tree with height h = 2^(h+1) - 1 (This is also the total number of nodes in a perfect binary tree of height h)
// Minimum number of nodes in a binary tree with height h = h + 1 (In the case of a linear structure, i.e., every node has only one child except the leaf node)
// For a binary tree with n nodes, the minimum possible height is ceil(log2(n+1)) - This ensures the tree is as complete as possible
// For a binary tree with n nodes, the maximum possible height is n - 1, which occurs when the tree is a linear chain (each node has only one child except the last one)

// Representation of a binary tree using linked list
#include<iostream>
#include<queue>
#include<vector>

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorder(Node*& root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);

}

void preorder(Node*& root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node*& root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

std::vector< std::vector<char> > levelorder(Node*& root) {
    std::vector< std::vector<char> > result;
    if (!root) return result;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<char> currentLevelElements;

        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            currentLevelElements.push_back(node->data);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevelElements);
    }

    return result;
}

int count(Node*& root) {
    if (!root) return 0;

    return count(root->left) + count(root->right) + 1;
}

int height(Node*& root) {
    int x = 0, y = 0;

    if (!root) return 0;

    x = height(root->left);
    y = height(root->right);

    return x > y ? x + 1 : y + 1;
}

int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->right = new Node('G');
    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    postorder(root);
    std::cout << std::endl;

    std::cout << count(root) << std::endl;
    std::cout << height(root) << std::endl;

    std::vector< std::vector<char> > result = levelorder(root);
    for (int i = 0; i < result.size(); i++) {
        std::vector<char> level = result[i];
        for (int i = 0; i < level.size(); i++) {
            std::cout << level[i] << " ";
        }
        std::cout << std::endl;
    }
}