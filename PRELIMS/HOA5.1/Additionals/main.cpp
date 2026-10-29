#include <iostream>
#include "queueCircleArr.h"

int main() {
    std::cout << "1. Testing Default Constructor" << std::endl;
    queueArr<int> q1;
    
    std::cout << "\n2. Testing Enqueue" << std::endl;
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);

    std::cout << "Front element: " << q1.Front() << std::endl;
    std::cout << "Back element: " << q1.Back() << std::endl;

    std::cout << "\n3. Testing Dequeue" << std::endl;
    q1.Dequeue();
    std::cout << "Front element after dequeue: " << q1.Front() << std::endl;

    std::cout << "\n4. Testing Constructor & Circular Wrapping" << std::endl;
    queueArr<std::string> q2(3);
    q2.Enqueue("A");
    q2.Enqueue("B");
    q2.Enqueue("C");
    
    q2.Enqueue("D"); 

    q2.Dequeue(); 
    q2.Enqueue("E");

    std::cout << "New Front: " << q2.Front() << std::endl;
    std::cout << "New Back: " << q2.Back() << std::endl;

    std::cout << "\n5. Testing Copy Constructor" << std::endl;
    queueArr<std::string> q3(q2);
    std::cout << "q3 Front (copied): " << q3.Front() << std::endl;

    std::cout << "\n6. Testing Copy Assignment Operator" << std::endl;
    queueArr<std::string> q4;
    q4 = q2;
    std::cout << "q4 Front (assigned): " << q4.Front() << std::endl;

    std::cout << "\n7. Testing Clear and Empty/Back checks" << std::endl;
    q1.Clear();
    q1.Front(); 

    std::cout << "\nEnd of Program" << std::endl;
    return 0;
}