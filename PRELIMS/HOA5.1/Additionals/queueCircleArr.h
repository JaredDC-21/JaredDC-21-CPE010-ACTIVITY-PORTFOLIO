#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr{
    private:
        T* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front, q_back;

    public:
        queueArr(size_t capacity);
        queueArr();
        ~queueArr();

        bool Empty();
        bool Full();
        size_t Size();
        void Clear();

        T Front();
        T Back();
        void Enqueue(T newData); 
        void Dequeue();          

        queueArr(const queueArr &other);
        
        queueArr &operator = (const queueArr &other);
};

template <typename T>
queueArr<T>::queueArr(size_t capacity){
    q_capacity = capacity;

    q_size = 0;

    q_front = 0;
    q_back = -1;

    q_array = new T[q_capacity];
    std::cout<<"Constructor was called\n";
}

template <typename T>
bool queueArr<T>::Empty(){
    return q_size == 0;
}

template <typename T>
bool queueArr<T>::Full(){
    return q_size == q_capacity;
}

template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

template <typename T>
queueArr<T>::queueArr(){
    q_capacity = 10;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
    std::cout<<"Default Constructor was called\n";
}

template <typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
    std::cout<<"Destructor was called\n";
}

template <typename T>
queueArr<T>::queueArr(const queueArr &other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; ++i) {
        q_array[i] = other.q_array[i];
    }
    std::cout<<"Copy Constructor was called\n";
}

template <typename T>
queueArr<T> &queueArr<T>::operator = (const queueArr &other){
    if (this == &other) {
        return *this;
    }

    delete[] q_array;

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; ++i) {
        q_array[i] = other.q_array[i];
    }

    std::cout<<"Copy Assignment Operator was called\n";
    return *this;
}

template <typename T>
void queueArr<T>::Clear(){
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

template <typename T>
T queueArr<T>::Front(){
    if(Empty()){
        std::cout <<"The Queue is Empty\n";
        return T{};
    }

    return q_array[q_front];
}

template <typename T>
T queueArr<T>::Back(){
    if(Empty()){
        std::cout <<"The Queue is Empty\n";
        return T{};
    }

    return q_array[q_back];
}

template <typename T>
void queueArr<T>::Enqueue(T newData){
    if(Full()){
        std::cout<<"Queue is full"<<std::endl;
        return;
    }

    q_back = (q_back + 1) % q_capacity;
    q_array[q_back] = newData;
    q_size++;
}

template <typename T>
void queueArr<T>::Dequeue(){
    if(Empty()){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    q_front = (q_front + 1) % q_capacity;

    q_size--;

    if(q_size == 0){
        q_front = 0;
        q_back = -1;
    }
}

#endif

