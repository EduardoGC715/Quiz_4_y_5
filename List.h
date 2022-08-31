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
    //Se elimina el puntero searchBehind: Los nodos ya poseen doble enlace
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
            //El anterior de newNode se le asigna la ultima posicion
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
            //Llamado de find para actualizar puntero searchPosition.(No borrar)
            T* result = find(pPosition);

            newNodo->setNext(searchPosition);
            if (searchPosition->getPrevious()!=NULL) {
                //Anterior a newNodo es el (anterior de searchPosition)
                newNodo->setPrevious(searchPosition->getPrevious());
                //El siguiente al (anterior de searchPosition) es newNodo
                searchPosition->getPrevious()->setNext(newNodo);
                //El anterior de searchPosition es NewNodo
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
                //Llamado de find para actualizar puntero searchPosition. (No borrar)

                T* data = find(pPosition);
                //desenlaza *anterior de searchPosition
                searchPosition->getPrevious()->setNext(searchPosition->getNext());

                if (searchPosition==last) {
                    //Actualiza puntero last.
                    last = searchPosition->getPrevious();
                    last->setNext(NULL);
                }
                else{
                    //Desenlaza *siguiente de searchPosition. Solo si no es el ultimo.
                    searchPosition->getNext()->setPrevious(searchPosition->getPrevious());
                }
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
