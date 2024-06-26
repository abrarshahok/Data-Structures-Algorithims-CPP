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

void inorder(Node*& bt) {
    if (bt == nullptr) return;
    inorder(bt->left);
    std::cout << bt->data << " ";
    inorder(bt->right);

}

void preorder(Node*& bt) {
    if (bt == nullptr) return;
    std::cout << bt->data << " ";
    preorder(bt->left);
    preorder(bt->right);

}

void postorder(Node*& bt) {
    if (bt == nullptr) return;
    postorder(bt->left);
    postorder(bt->right);
    std::cout << bt->data << " ";
}

int main() {
    Node* bt = new Node('A');
    bt->left = new Node('B');
    bt->right = new Node('C');
    bt->left->left = new Node('D');
    bt->left->right = new Node('E');
    bt->right->left = new Node('F');
    bt->right->right = new Node('G');
    preorder(bt);
    std::cout << std::endl;
    inorder(bt);
    std::cout << std::endl;
    postorder(bt);
    std::cout << std::endl;
}