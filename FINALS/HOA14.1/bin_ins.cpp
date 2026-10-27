#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> inputSizes = {1000, 10000, 100000};
    int target = -1; 

    std::cout << std::left 
              << std::setw(18) << "INPUT SIZE (N)" 
              << std::setw(32) << "Binary Search" 
              << std::setw(32) << "Linear Search" 
              << "\n";
    std::cout << std::string(80, '-') << "\n";

    for (int n : inputSizes) {
        std::vector<int> data(n);
        for (int i = 0; i < n; ++i) {
            data[i] = i * 2; 
        }

        int iterations = 1000;
        auto startBS = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) {
            volatile int res = binarySearch(data, target);
            (void)res;
        }
        auto endBS = std::chrono::high_resolution_clock::now();
        double timeBS = std::chrono::duration<double, std::micro>(endBS - startBS).count() / iterations;

        auto startLS = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) {
            volatile int res = linearSearch(data, target);
            (void)res;
        }
        auto endLS = std::chrono::high_resolution_clock::now();
        double timeLS = std::chrono::duration<double, std::micro>(endLS - startLS).count() / iterations;

        std::cout << std::left 
                  << std::setw(18) << n 
                  << std::setw(32) << (std::to_string(timeBS) + " ms") 
                  << std::setw(32) << (std::to_string(timeLS) + " ms") 
                  << "\n";
    }

    return 0;
}