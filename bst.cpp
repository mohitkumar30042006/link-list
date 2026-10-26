
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

// 1. INSERTION
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// 2. SEARCHING
bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum value node
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// 3. DELETION (ALL THREE CASES)
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // CASE 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // CASE 2: Node has one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // CASE 3: Node has two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insertion
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "BST Inorder: ";
    inorder(root);

    // Searching
    int key = 40;
    if (search(root, key))
        cout << "\n" << key << " found in BST";
    else
        cout << "\n" << key << " not found in BST";

    // Deletion
    root = deleteNode(root, 20);  // Case 1: Leaf node
    root = deleteNode(root, 30);  // Case 2: One child (after 20 is deleted)
    root = deleteNode(root, 50);  // Case 3: Two children

    cout << "\nBST after deletion: ";
    inorder(root);

    cout << endl;
    return 0;
}
