#include <iostream>

//Memoization table 12-2

int memo[101]; // we will initialize the elements to -1 ( -1 means, not solved it yet )
int getMinSteps ( int n )
{
    if ( n == 1 ) return 0; // base case
    if( memo[n] != -1 ) return memo[n]; // we have solved it already :)
    int r = 1 + getMinSteps( n - 1 ); // '-1' step . 'r' will contain the optimal answer finally
    if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2 ) ) ; // '/2' step
    if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3 ) ) ; // '/3' step
    memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
    return r;
}

int main() {

    //memoization
    int testCases[] = {1, 4, 7, 10};

    for (int n : testCases) {
        // Reset memo array to -1 before each test case
        for (int i = 0; i <= n; i++) {
            memo[i] = -1;
        }
        
        std::cout << "n = " << n << " - Min Steps: " << getMinSteps(n) << std::endl;

    }

    return 0;
}
