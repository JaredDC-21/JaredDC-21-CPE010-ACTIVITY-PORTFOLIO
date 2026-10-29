#include <iostream>
#include "queueArr.h"

int main(){

    char queue[MAX];
    int front = -1;
    int back = -1;

    enqueue('D', queue, &front, &back);
    enqueue('Y', queue, &front, &back);
    enqueue('L', queue, &front, &back);
    enqueue('A', queue, &front, &back);
    enqueue('N', queue, &front, &back);

    std::cout << "Queue: ";
    displayQ(queue, &front, &back);

    std::cout << "Front: " << showFront(queue, &front) << '\n';
    std::cout << "Back: " << showBack(queue, &back) << '\n';

    dequeue(queue, &front, &back);

    std::cout << "After dequeue: ";
    displayQ(queue, &front, &back);

    return 0;
}