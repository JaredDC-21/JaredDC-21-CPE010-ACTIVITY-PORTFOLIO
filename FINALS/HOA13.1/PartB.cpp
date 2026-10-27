#include <iostream>
#include <thread>

int global_var = 0;

void add(int value) {
    global_var += value;
}

int main() {
    //Createing 3 threads
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Display (Initial before T1 join): " << global_var << std::endl;
    T1.join();

    std::cout << "Display (After T1 join): " << global_var << std::endl;
    T2.join();

    std::cout << "Display (After T2 join): " << global_var << std::endl;
    T3.join();

    std::cout << "Display (Final/After T3 join): " << global_var << std::endl;

    return 0;
}
