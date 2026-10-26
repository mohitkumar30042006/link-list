
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;

    Node(int v) {
        data = v;
        height = 1;
        left = right = NULL;
    }
};

int h(Node* n) {
    return n ? n->height : 0;
}

int balance(Node* n) {
    return n ? h(n->left) - h(n->right) : 0;
}

void update(Node* n) {
    n->height = 1 + max(h(n->left), h(n->right));
}

// Right rotation (LL)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    update(y);
    update(x);
    return x;
}

// Left rotation (RR)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    update(x);
    update(y);
    return y;
}

Node* insert(Node* root, int v) {
    if (!root) return new Node(v);

    if (v < root->data) root->left = insert(root->left, v);
    else if (v > root->data) root->right = insert(root->right, v);
    else return root;

    update(root);
    int b = balance(root);

    // LL
    if (b > 1 && v < root->left->data)
        return rightRotate(root);

    // RR
    if (b < -1 && v > root->right->data)
        return leftRotate(root);

    // LR
    if (b > 1 && v > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (b < -1 && v < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool isBalanced(Node* root) {
    if (!root) return true;

    int b = balance(root);
    return abs(b) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nBalanced: "
         << (isBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}
