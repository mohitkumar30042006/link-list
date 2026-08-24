#include <iostream>
using namespace std;

class CircularQueue {
    int queue[5];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        // Check if queue is full
        if ((rear + 1) % 5 == front) {
            cout << "Queue is Full" << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % 5;
        queue[rear] = value;
    }

    void dequeue() {
        // Check if queue is empty
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << queue[front] << " deleted" << endl;

        // Only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % 5;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }

        int i = front;

        cout << "Queue: ";

        while (true) {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 5;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
