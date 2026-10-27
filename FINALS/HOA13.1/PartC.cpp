#include <iostream>
#include <thread>
#include <utility>

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = i + 1; j < arrSize; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void printArray(const std::string& label, const int arr[], size_t size) {
    std::cout << label << ": ";
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {88, 14, 45, 6, 71, 30, 52};

    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "BEFORE SORTING" << std::endl;
    printArray("Array 1", arr1, size1);
    printArray("Array 2", arr2, size2);

    //multithreading forlaunching 2 threads to sort independent arrays concurrently
    std::thread t1(bubbleSort<int>, arr1, size1);
    std::thread t2(bubbleSort<int>, arr2, size2);

    t1.join();
    t2.join();

    std::cout << "AFTER MULTITHREADED BUBBLE SORT" << std::endl;
    printArray("Array 1", arr1, size1);
    printArray("Array 2", arr2, size2);

    return 0;
}