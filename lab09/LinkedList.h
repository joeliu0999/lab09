//
// Created by User on 11/9/2022.
//

#ifndef LAB09_LINKEDLIST_H
#define LAB09_LINKEDLIST_H
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
    Node(T _data, Node *_prev, Node *_next = nullptr) : data(_data), prev(_prev), next(_next){}
};

template<typename T>
class LinkedList {
public:

    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
    class Iterator{
    public:
        Node<T> *IteratorNode;
        Iterator()
        {
            IteratorNode->next = nullptr;
            IteratorNode->prev = nullptr;
        }
        T operator*() const
        {
            return IteratorNode->data;
        }
        Iterator& operator++(){
            Iterator theIterator = *IteratorNode;
            IteratorNode = IteratorNode->next;
            return theIterator;
        }
        Iterator& operator--(){
            Iterator theIterator = *IteratorNode;
            IteratorNode = IteratorNode->prev;
            return theIterator;
        }
        bool operator==(Iterator const& rhs)
        {
            return IteratorNode == rhs.IteratorNode;
        }
        bool operator!=(Iterator const& rhs)
        {
            return IteratorNode != rhs.IteratorNode;
        }
    };
private:
    Iterator myIterator;
public:
    Iterator begin() const
    {
        while(true){
            if (myIterator.IteratorNode->prev==nullptr) break;  //stop when reach start
            myIterator=myIterator.IteratorNode->prev;    //go back one
        }
        return  myIterator;
    }
    Iterator tail() const
    {
        while(true)
        {
            if(myIterator.IteratorNode->next==nullptr) break;
            myIterator=myIterator.IteratorNode->next;
        }
        return myIterator;
    }
    Iterator end() const
    {
        while(true)
        {
            if(myIterator.IteratorNode->next==nullptr) break;
            myIterator=myIterator.IteratorNode->next;
        }
        myIterator++;
        return myIterator;
    }
    bool isEmpty() const
    {
        if (first == nullptr)
            return true;
        else
            return false;
    }
    T getFront() const
    {
        return first->data;
    }
    T getBack() const
    {
        return last->data;
    }
    bool contains(T element) const
    {
        myIterator.IteratorNode = first;
        while(myIterator.IteratorNode->next != nullptr)
        {
            if(myIterator.IteratorNode->data == element)
                return true;
        }
        return false;
    }
    void enqueue (T element)
    {
        Node<T>* newNode;
        if (first == nullptr)
        {
            newNode = new Node(element, nullptr);
        }
        else
        {
            newNode = new Node(element, last);
        }
        if (first == nullptr)
        {
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    void dequeue()
    {
        Node<T> *removeMe = first;
        if (last == first)
            last = nullptr;
        first = first->next; //make first point to second one
        delete removeMe; //delete the last one
    }
    void pop()
    {
        Node<T> *removeMe = last;
        if (last == first)
            first = nullptr;
        last = last->prev; //make last point to second last one
        delete removeMe; //delete the last one

    }
    void clear(){
        while(last!=nullptr) //while there is still element in list
        {
            Node<T> *temp = last;
            last = last->prev;
            delete temp;
        }
    }
    void remove(T element)
    {
        Node<T> *temp=first; //create temp so the pointer before os not lost
        while(temp->data!=element){
            if(temp==nullptr){
                cout<<"no such element in the list";
                break;
            }
            temp=temp->next;
        }
        if(temp->data==element){
            Node<T> *removeMe=temp;
            temp=temp->prev; //connect the Node before the removed-Node to the Node after the removed-Node
            temp=removeMe->next;

            delete removeMe;
        }
    }
};
#endif //LAB09_LINKEDLIST_H
