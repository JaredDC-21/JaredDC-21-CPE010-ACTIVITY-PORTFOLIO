#include <iostream>
#include <cstdlib>
#include "sorting.h"

int main() {
    const int SIZE = 100;

    int original[SIZE];
    int shellArray[SIZE];
    int mergeArray[SIZE];
    int quickArray[SIZE];

    srand(12345);

    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 100;
    }

    // Copy the same unsorted array
    for (int i = 0; i < SIZE; i++) {
        shellArray[i] = original[i];
        mergeArray[i] = original[i];
        quickArray[i] = original[i];
    }

    std::cout << "ORIGINAL ARRAY:\n";
    displayArray(original, SIZE);

    shellSort(shellArray, SIZE);
    std::cout << "\n\nSHELL SORT:\n";
    displayArray(shellArray, SIZE);

    mergeSort(mergeArray, 0, SIZE - 1);
    std::cout << "\n\nMERGE SORT:\n";
    displayArray(mergeArray, SIZE);

    quickSort(quickArray, 0, SIZE - 1);
    std::cout << "\n\nQUICK SORT:\n";
    displayArray(quickArray, SIZE);

    // Supplementary Problem 1

    int left[] = {4, 3, 2};
    int right[] = {7, 9, 8};

    int leftSize = sizeof(left) / sizeof(left[0]);
    int rightSize = sizeof(right) / sizeof(right[0]);

    std::cout << "\n\nProblem 1\n";
    std::cout << "Left sublist before sorting: ";
    displayArray(left, leftSize);
    std::cout << "\nRight sublist before sorting: ";
    displayArray(right, rightSize);

    insertionSort(left, leftSize);
    insertionSort(right, rightSize);

    std::cout << "\n\nLeft sublist after Insertion Sort: ";
    displayArray(left, leftSize);
    std::cout << "\nRight sublist after Insertion Sort: ";
    displayArray(right, rightSize);

    std::cout << "\n\nFinal result with pivot 6: ";
    displayArray(left, leftSize);
    std::cout << "6 ";
    displayArray(right, rightSize);

    return 0;
}

