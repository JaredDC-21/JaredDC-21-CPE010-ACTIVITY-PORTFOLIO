#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char> *front = nullptr;
    qNode<char> *back = nullptr;

    enqueue('J', &front, &back);
    enqueue('A', &front, &back);
    enqueue('R', &front, &back);
    enqueue('E', &front, &back);
    enqueue('D', &front, &back);
    
    std::cout<<"Initial Queue: ";
    displayQ(&front, &back);

    std::cout <<"Dequeuing\n";
    dequeue(&front, &back);

    std::cout << "Showing New Front: " << showFront(&front) <<'\n';
    std::cout << "Showing New Back: " << showBack(&back) <<'\n';

    std::cout<<"Showing New Queue: ";
    displayQ(&front, &back);

    return 0;
}

