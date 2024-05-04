#ifndef PROJECT_LINKEDNODE_H
#define PROJECT_LINKEDNODE_H

template <typename T>
struct LinkedNode {
    T data;
    LinkedNode* next;

    LinkedNode(const T& newData) : data(newData), next(nullptr) {}
};

#endif //PROJECT_LINKEDNODE_H
