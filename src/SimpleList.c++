#ifndef SIMPLELIST_HPP
#define SIMPLELIST_HPP

#include <iostream>
#include "Node.c++"

using namespace std;

template <typename T>
class SimpleList {
private:    
    Node<T>* head;

public:
    SimpleList() : head(nullptr) {}

    int size(){
        int total = 0;
        Node<T>* auxNode = head;

        while (auxNode){
            total++;
            auxNode = auxNode->getNext();
        }
        return total;
    }

    bool isEmpty(){
        return !head;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->getNext()) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }

    T pull() {
        if (!head){
            throw std::runtime_error("La lista está vacía");
        }
    
        if (!head->getNext()) {
            T value = head->getData();
            delete head;
            head = nullptr;
            return value;
        }
    
        Node<T>* temp = head;
        while (temp->getNext()->getNext()) {
            temp = temp->getNext();
        }
        
        T value = temp->getNext()->getData();
        delete temp->getNext();
        temp->setNext(nullptr);

        return value;
    }

    void remove(T value) {
        if (!head){
            throw std::runtime_error("La lista está vacía");
        }
    
        if (head->getData() == value) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
            return;
        }
    
        Node<T>* temp = head;
        while (temp->getNext() && temp->getNext()->getData() != value) {
            temp = temp->getNext();
        }
    
        if (!temp->getNext()) return;
    
        Node<T>* nodeToDelete = temp->getNext();
        temp->setNext(nodeToDelete->getNext());
        delete nodeToDelete;
    }
    
    T removeAt(int position) {
        if (!head || position < 0){
            throw std::runtime_error("Posicion invalida o lista vacia");
        }
    
        if (position == 0) {
            Node<T>* temp = head;
            T value = temp->getData();
            head = head->getNext();
            delete temp;
            return value;
        }
    
        Node<T>* temp = head;
        for (int i = 0; temp->getNext() && i < position - 1; i++) {
            temp = temp->getNext();
        }
    
        if (!temp->getNext()){
            throw std::runtime_error("Posición fuera de rango.");
        }
    
        Node<T>* nodeToDelete = temp->getNext();
        T value = nodeToDelete->getData();
        temp->setNext(nodeToDelete->getNext());
        delete nodeToDelete;

        return value;
    }

    T get(int index) {
        Node<T>* temp = head;
        for (int i = 0; temp && i < index; i++) {
            temp = temp->getNext();
        }
        return temp ? temp->getData() : T();  
    }
    

    bool exists(T value) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->getData() == value) return true;
            temp = temp->getNext();
        }
        return false;
    }

    void showList() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->getData() << " -> ";
            temp = temp->getNext();
        }
    }

    ~SimpleList() {
        Node<T>* temp;
        while (head) {
            temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

#endif
