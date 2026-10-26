
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Recursive insertion in a Binary Tree
bool insert(Node* root, int value) {
    if (root->left == NULL) {
        root->left = new Node(value);
        return true;
    }

    if (insert(root->left, value))
        return true;

    if (root->right == NULL) {
        root->right = new Node(value);
        return true;
    }

    return insert(root->right, value);
}

// Inorder: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(10);

    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
