#include <iostream>
using namespace std;
#define MAX_SIZE 256;

template <class T> class Queue {
private:
    int front;
    int rear;
    int size;
    T *data;
public:
    Queue(int size) {
        front = 0;
        rear = 0;
        this->size = size + 1;
        data = new T[size];
    }

    ~Queue() {
        delete[] data;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(T elem) {
        if (isFull()) {
            cout << "Error : Queue is Full!" << endl;
        } else {
            rear = (rear + 1) % size;
            data[rear] = elem;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Error : Queue is Empty!" << endl;
        } else {
            front = (front + 1) % size;
            return data[front];
        }
    }

    T peek() {
        if (isEmpty()) {
            cout << "Error : Queue is Empty!" << endl;
        } else {
            return data[(front + 1) % size];
        }
    }
    
    void display() {
        int maxi = (front < rear) ? rear : rear + size;
        for (int i = front + 1; i <= maxi; i++) {
            cout << data[i % size] << " ";
        }
        cout << endl;
    }
};