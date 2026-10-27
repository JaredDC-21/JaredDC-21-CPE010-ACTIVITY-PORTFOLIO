//experimental Analysis

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

bool is_unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

void run_experiment(int size) {
    std::vector<int> A(size);
    for (int i = 0; i < size; i++) {
        A[i] = i;
    }

    //measure execution time
    auto start = std::chrono::high_resolution_clock::now();
    bool result = is_unique(A);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Input Size (N = " << size << "): " << duration << " microseconds" << std::endl;
}

int main() {
    std::cout << "Problem 1: Experimental Analysis" << std::endl;
    run_experiment(1000);
    run_experiment(5000);
    run_experiment(10000);
    run_experiment(20000);
    return 0;
}