#include "Node.h"
#include "event.h"

#ifndef LIST

#define LIST 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <class T>
class List {
private:
    Node<T> *first;
    Node<T> *last;
    int quantity;
    bool empty;
    Node<T> *searchPosition = NULL;
    //Node<T> *searchBehind = NULL;

public:
    List() {
        first = NULL;
        last = NULL;
        quantity = 0;
        empty = true;
    }

    void add(T *pData) {
        Node<T> *newNode = new Node<T>(pData);

        if (quantity>0) {
            newNode->setPrevious(last);
            this->last->setNext(newNode);
        } else {
            this->first = newNode;
        }
        this->last = newNode;

        empty = false;
        quantity++;
    }

    Node<T>* getFirst() {
        return this->first;
    }

    int getSize() {
        return quantity;
    }

    bool isEmpty() {
        return !quantity;
    }

    T* find(int pPosition) {
        T* result = NULL;
        searchPosition = this->first;

        if (pPosition<getSize()) {
            while(pPosition>0) {
                searchPosition = searchPosition->getNext();
                pPosition--;
            }
            result = searchPosition->getData();
        }

        return result;
    }

    // es que si el position es mayor a la cantidad, entonces inserto al final
    void insert(int pPosition, T *pData) {

        if (pPosition<getSize() && first!=NULL) {
            Node<T> *newNodo = new Node<T>(pData);

            T* result = find(pPosition);

            newNodo->setNext(searchPosition);
            if (searchPosition->getPrevious()!=NULL) {
                newNodo->setPrevious(searchPosition->getPrevious());
                searchPosition->getPrevious()->setNext(newNodo);
                searchPosition->setPrevious(newNodo);

            } else {
                this->first = newNodo;
            }

            quantity++;
        } else {
            add(pData);
        }
    }

    bool remove(int pPosition) {
        bool result = false;
        if (first!=NULL && pPosition<getSize()) {
            Node<T> *search = first;
            if (pPosition!=0) {
                //Llamado de find para actualizar puntero searchPosition.
                T* data = find(pPosition);
                searchPosition->getNext()->setPrevious(searchPosition->getPrevious());
                searchPosition->getPrevious()->setNext(searchPosition->getNext());
                cout<<"antes del if";
                if (searchPosition==last) {
                    cout<<"dentro del if";
                    last = searchPosition->getPrevious();
                    last->setNext(NULL);
                }
                cout<<"despues del if";
                searchPosition->setNext(NULL);
                searchPosition->setPrevious(NULL);

            } else {
                first = first->getNext();
                search->setNext(NULL);
                delete search;
            }
            quantity--;
        }
        return result;
    }
};

#endif
