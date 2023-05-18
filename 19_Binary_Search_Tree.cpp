#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node *root;
    BST() : root(NULL) {}

    void insert(int data)
    {
        node *newnode = new node(data);
        if (root == NULL)
        {
            root = newnode;
            return;
        }

        node *current = root;
        while (true)
        {
            if (data < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = newnode;
                    return;
                }
                current = current->left;
            }

            else if (data > current->data)
            {
                if (current->right == NULL)
                {
                    current->right = newnode;
                    return;
                }
                current = current->right;
            }

            else
            {
                cout << data << " : Already Found!\nCan't add Dublicates!" << endl;
                return;
            }
        }
    }

    void Rinsert(node *&root, int data)
    {

        node *newnode = new node(data);
        if (root == NULL)
        {
            root = newnode;
            return;
        }

        if (data == root->data)
            return;

        else if (data < root->data)
            Rinsert(root->left, data);

        else
            Rinsert(root->right, data);
    }

    bool R_search(node *&Node, int key)
    {
        if (Node == NULL)
            return false;

        if (key < Node->data)
            R_search(Node->left, key);

        else if (key > Node->data)
            R_search(Node->right, key);

        return true;
    }

    void delete_node(node *&Node, int key)
    {
        if (Node == NULL)
            return;

        if (key < Node->data)
        {
            delete_node(Node->left, key);
            return;
        }
        else if (key > Node->data)
        {
            delete_node(Node->right, key);
            return;
        }

        if (Node->left == NULL && Node->right == NULL)
        {
            delete Node;
            Node = NULL;
        }

        else if (Node->left == NULL)
        {
            node *temp = Node;
            Node = Node->right;
            delete temp;
        }

        else if (Node->right == NULL)
        {
            node *temp = Node;
            Node = Node->left;
            delete temp;
        }

        else
        {
            if (Height(Node->left) > Height(Node->right))
            {
                node *min = InPre(Node->left);
                Node->data = min->data;
                delete_node(Node->left, min->data);
            }
            else
            {
                node *min = InSucc(Node->right);
                Node->data = min->data;
                delete_node(Node->right, min->data);
            }
        }
    }

    node *InPre(node *&Node)
    {
        node *temp = Node;
        while (temp && temp->right != NULL)
            temp = Node->right;
        return temp;
    }

    node *InSucc(node *&Node)
    {
        node *temp = Node;
        while (temp && temp->left != NULL)
            temp = Node->left;
        return temp;
    }

    int Height(node *&Node)
    {
        if (Node == NULL)
            return 0;
        int l, r;
        l = Height(Node->left);
        r = Height(Node->right);

        return (l > r) ? (l + 1) : (r + 1);
    }

    void travserse_preorder(node *&Node)
    {
        if (Node == NULL)
            return;

        cout << Node->data << " ";
        travserse_preorder(Node->left);
        travserse_preorder(Node->right);
    }

    void travserse_inorder(node *&Node)
    {
        // This will Sort Elements of Tree
        if (Node == NULL)
            return;

        travserse_inorder(Node->left);
        cout << Node->data << " ";
        travserse_inorder(Node->right);
    }

    void travserse_postorder(node *&Node)
    {
        if (Node == NULL)
            return;

        travserse_postorder(Node->left);
        travserse_postorder(Node->right);
        cout << Node->data << " ";
    }
};

int main()
{
    BST tree;
    tree.insert(20);
    tree.insert(30);
    tree.insert(10);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.Rinsert(tree.root, 25);
    tree.insert(5);
    tree.insert(15);
    bool ans = tree.R_search(tree.root, 12);
    cout << ans << endl;
    tree.delete_node(tree.root, 20);
    tree.delete_node(tree.root, 25);
    tree.travserse_inorder(tree.root);
}