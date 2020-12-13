#include <iostream>
using namespace std;
#define MAX_SIZE 256;

template <class T> class Queue {
private:
    int front;
    int rear;
    int size;
    T *elements;
public:
    Queue(int size) {
        front = 0;
        rear = 0;
        this->size = size;
        elements = new T[size];
    }

    ~Queue() {
        delete[] elements;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == size;
    }

    void enqueue(T elem) {
        if (isFull()) {
            cout << "Error : Queue is Full!" << endl;
        } else {
            elements[rear++] = elem;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Error : Queue is Empty!" << endl;
        } else {
            return elements[front++];
        }
    }

    T peek() {
        if (isEmpty()) {
            cout << "Error : Queue is Empty!" << endl;
        } else {
            return elements[front + 1];
        }
    }
    
    void display() {
        for (int i = front; i < rear; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};