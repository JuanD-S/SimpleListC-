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

    void pull() {
        if (!head) return;
    
        if (!head->getNext()) {
            delete head;
            head = nullptr;
            return;
        }
    
        Node<T>* temp = head;
        while (temp->getNext()->getNext()) {
            temp = temp->getNext();
        }
    
        delete temp->getNext();
        temp->setNext(nullptr);
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
