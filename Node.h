#include <iostream>

#ifndef NODE

#define NODE 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Node {
private:
    T *data;
    Node *next;
    Node *previous;

public:
    Node() {
        data = NULL;
        next = NULL;
        previous = NULL;
    }

    Node(T *pData) {
        this->data = pData;
        next = NULL;
        previous = NULL;
    }

    T* getData() {
        return data;
    }

    Node* getNext() {
        return next;
    }

    Node* getPrevious() {
        return previous;
    }

    void setNext(Node *pValue) {
        this->next = pValue;
    }

    void setPrevious(Node *pValue) {
        this->previous = pValue;
    }
};

#endif
