#ifndef PROJECT_STACK_H
#define PROJECT_STACK_H

#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& newData) : data(newData), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const T& interaction) {
        Node* newNode = new Node(interaction);
        newNode->next = top;
        top = newNode;
    }

    void displayHistory() const {
        Node* current = top;
        std::cout << "Interaction History:\n";
        while (current != nullptr) {
            std::cout << current->data << "\n";
            current = current->next;
        }
    }
};

#endif //PROJECT_STACK_H
