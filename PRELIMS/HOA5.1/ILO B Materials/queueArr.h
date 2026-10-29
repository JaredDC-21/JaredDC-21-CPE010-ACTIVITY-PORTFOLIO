#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <iostream>

const int MAX = 10;

//enqueue operation
template <typename T>
void enqueue(T newData, T queue[], int *frontPtr, int *backPtr){
    //check if the queue is full
    if((*backPtr) == MAX - 1){
        std::cout << "The queue is already full\n";
        return;
    }

    //inserting into an empty queue
    if((*frontPtr) == -1 && (*backPtr) == -1){
        (*frontPtr) = 0;
        (*backPtr) = 0;
        queue[*backPtr] = newData;
        return;
    }

    //inserting into a non-empty queue
    (*backPtr)++;
    queue[*backPtr] = newData;
}

//dequeue operation
template <typename T>
void dequeue(T queue[], int *frontPtr, int *backPtr){

    //check if the queue is empty
    if((*frontPtr) == -1 && (*backPtr) == -1){
        std::cout << "The queue is already empty\n";
        return;
    }

    //check if the queue has only one element
    if((*frontPtr) == (*backPtr)){
        (*frontPtr) = -1;
        (*backPtr) = -1;
        return;
    }

    //remove the front element
    (*frontPtr)++;
}

//check the front
template <typename T>
T showFront(T queue[], int *frontPtr){

    if(*frontPtr == -1){
        std::cout << "Queue is empty\n";
        return T();
    }

    return queue[*frontPtr];
}

template <typename T>
T showBack(T queue[], int *backPtr){

    if(*backPtr == -1){
        std::cout << "Queue is empty\n";
        return T();
    }

    return queue[*backPtr];
}

//display all
template <typename T>
void displayQ(T queue[], int *frontPtr, int *backPtr){

    if((*frontPtr) == -1 && (*backPtr) == -1){
        std::cout << "The queue is already empty\n";
        return;
    }

    for(int i = *frontPtr; i <= *backPtr; i++){
        std::cout << queue[i] << " ";
    }

    std::cout << '\n';
}

#endif