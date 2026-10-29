#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <iostream>

template <typename T>
class Node{
public:
    T data{};
    Node<T>* next = nullptr;
};

template <typename T>
Node<T>* head = nullptr;

template <typename T>
void push(T newData){
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
T pop(){
    if(isEmpty<T>()){
        return T{};
    }

    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = head<T>->next;

    delete temp;
    return tempVal;
}

template <typename T>
T Top(){
    if(isEmpty<T>())
        return T{};

    return head<T>->data;
}

#endif