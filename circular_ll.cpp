#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class CircularList {
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    CircularList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Circular Linked List: ";
    list.display();

    return 0;
}
