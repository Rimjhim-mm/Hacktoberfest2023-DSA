#include <iostream>

using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, capacity, size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = item;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    int frontValue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return arr[front];
    }
};

int main() {
    int capacity, choice, item;
    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    do {
        cout << "Circular Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to enqueue: ";
                cin >> item;
                cq.enqueue(item);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                item = cq.frontValue();
                if (item != -1)
                    cout << "Front element: " << item << endl;
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
