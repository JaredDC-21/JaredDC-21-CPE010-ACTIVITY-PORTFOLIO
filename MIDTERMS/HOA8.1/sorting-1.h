#ifndef SORTING_H
#define SORTING_H

#include <iostream>

// Display Array
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

// Bubble Sort
template <typename T>
void bubbleSort(T arr[], int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        for (int j = i + 1; j < maxSize; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

// Routine Smallest
template <typename T>
int routine_smallest(T arr[], int k, int arrSize) {
    int position = k;
    T smallestElement = arr[k];

    for (int j = k + 1; j < arrSize; j++) {
        if (arr[j] < smallestElement) {
            smallestElement = arr[j];
            position = j;
        }
    }

    return position;
}

// Selection Sort
template <typename T>
void selectionSort(T arr[], int arrSize) {
    int min;

    for (int i = 0; i < arrSize; i++) {
        min = routine_smallest(arr, i, arrSize);
        std::swap(arr[i], arr[min]);
    }
}

// Insertion Sort
template <typename T>
void insertionSort(T arr[], int arrSize) {
    int k = 1, j;
    T temp;

    while (k < arrSize) {
        temp = arr[k];
        j = k - 1;

        while (j >= 0 && temp <= arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
        k++;
    }
}

template <typename T>
void shellSort(T arr[], int arrSize) {
    for (int interval = arrSize / 2; interval > 0; interval /= 2) {

        for (int i = interval; i < arrSize; i++) {
            T temp = arr[i];
            int j = i;

            while (j >= interval && arr[j - interval] > temp) {
                arr[j] = arr[j - interval];
                j -= interval;
            }

            arr[j] = temp;
        }
    }
}

// Merge Function
template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    T* leftArray = new T[leftSize];
    T* rightArray = new T[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

// Quick Sort Partition
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort
template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif