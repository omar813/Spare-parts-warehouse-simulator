#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

#include <stdexcept>
#include <iostream>
#include "LinkedNode.h"

using namespace std;

template <typename T>
class Queue {
private:
    LinkedNode<T>* front;
    LinkedNode<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const T& data) {
        LinkedNode<T>* newNode = new LinkedNode<T>(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        }

        LinkedNode<T>* temp = front;
        T data = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};


#endif //PROJECT_QUEUE_H
