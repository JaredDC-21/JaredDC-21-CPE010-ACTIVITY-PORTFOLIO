//Experimental Analysis

#include <iostream>
#include <chrono>

long long rpower(int x, int n) {
    if (n == 0) return 1;
    else return x * rpower(x, n - 1);
}


long long brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) { // odd
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else { // even
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

void run_power_experiment(int x, int n) {
    //measure rpower execution time
    auto start_r = std::chrono::high_resolution_clock::now();
    long long res_r = rpower(x, n);
    auto end_r = std::chrono::high_resolution_clock::now();
    auto duration_r = std::chrono::duration_cast<std::chrono::nanoseconds>(end_r - start_r).count();

    //measure brpower execution time
    auto start_br = std::chrono::high_resolution_clock::now();
    long long res_br = brpower(x, n);
    auto end_br = std::chrono::high_resolution_clock::now();
    auto duration_br = std::chrono::duration_cast<std::chrono::nanoseconds>(end_br - start_br).count();

    std::cout << "Exponent N = " << n << std::endl;
    std::cout << " rpower (Linear O(N)) : " << duration_r << " ns" << std::endl;
    std::cout << " brpower (Log O(logN)): " << duration_br << " ns" << std::endl;
    std::cout << " " << std::endl;
}

int main() {
    std::cout << "Problem 2: Experimental Analysis" << std::endl;
    
    run_power_experiment(2, 100);
    run_power_experiment(2, 1000);
    run_power_experiment(2, 10000);
    run_power_experiment(2, 100000);

    return 0;
}