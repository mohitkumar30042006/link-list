
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
int main() {
    Node* root = new Node(10);

    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
