//
// Created by User on 11/9/2022.
//

#ifndef LAB09_LINKEDLIST_H
#define LAB09_LINKEDLIST_H
#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
public:
    struct Node{
        T data;
        Node* next;
        Node* prev;
        Node(T _data, Node *_next = nullptr, Node *_prev = nullptr) : data(_data), next(_next), prev(_prev){}
    };
    Node *first = nullptr;
    Node *last = nullptr;
    class Iterator{
    private:
        Node *IteratorNode;
    public:
        Iterator();
        Iterator(Node* value);
        T operator*() const;
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(Iterator const& rhs);
        bool operator!=(Iterator const& rhs);
    };
    LinkedList<T>();
    Iterator begin() const;
    Iterator tail() const;
    Iterator end() const;
    bool isEmpty() const;
    T getFront() const;
    T getBack() const;
    bool contains(T element) const;
    void enqueue (T element);
    void dequeue();
    void pop();
    void clear();
    void remove(T element);
private:
    Iterator myIterator;
};

template<typename T>
LinkedList::Iterator::Iterator()
{
    IteratorNode = nullptr;
}
LinkedList::Iterator::Iterator(Node* value)
{
    IteratorNode = value;
}

template<typename T>
Iterator Linkedlist::Iterator::current(){
    return IteratorNode;
}
template<typename T>
T LinkedList::Iterator::operator*() const{
    return IteratorNode->next->data;
}
template<typename T>
Iterator& LinkedList::Iterator::operator++(){
    Iterator theIterator = *IteratorNode
    IteratorNode = IteratorNode->next;
    return theIterator;
}
template<typename T>
Iterator& LinkedList::Iterator::operator--(){
    Iterator theIterator = *IteratorNode
    IteratorNode = IteratorNode->prev;
    return theIterator;
}
template<typename T>
bool LinkedList::Iterator::operator==(Iterator const& rhs){
    return IteratorNode == rhs.IteratorNode;
}
template<typename T>
bool LinkedList::Iterator::operator!=(Iterator const& rhs){
    return IteratorNode != rhs.IteratorNode;
}

// linkedList methods
template<typename T>
LinkedList::LinkedList<T>()
{
    Node *first = nullptr;
    Node *last = nullptr;
}
template<typename T>
Iterator LinkedList::begin() const
{
    return Iterator(first);
}
template<typename T>
Iterator LinkedList::tail() const
{
    return Iterator(last);
}
template<typename T>
LinkedList::Iterator end() const
{
    return Iterator(last)++;
}
template<typename T>
bool isEmpty() const
{
    if (first = nullptr)
        return True;
    else
        return False;
}
template<typename T>
T getFront() const
{
    return *first;
}
template<typename T>
T getBack() const
{
    return *last;
}
#endif //LAB09_LINKEDLIST_H
