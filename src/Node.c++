#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;

public:

    Node(T data) : data(data), next(nullptr) {}

    T getData() const
    {
        return data;
    }

    void setData(T data)
    {
        this->data = data;
    }

    Node<T>* getNext() const
    {
        return next;
    }

    void setNext(Node<T> *nextNode)
    {
        next = nextNode;
    }
};

#endif 
