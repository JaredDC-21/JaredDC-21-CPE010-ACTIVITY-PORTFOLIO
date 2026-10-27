#include <iostream>
#include <algorithm>
#include "CountPaths.h"

int memo[1001];

int main(){
    int memoArr[] = {1, 4, 7, 10};
    
    // SUPPLEMENTARY: Count Paths with Cost
    int matrix[4][4] = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 21;
    std::cout << "\nNumber of valid paths: " << countPaths(matrix, 0, 0, targetCost) << '\n';

    return 0;
}