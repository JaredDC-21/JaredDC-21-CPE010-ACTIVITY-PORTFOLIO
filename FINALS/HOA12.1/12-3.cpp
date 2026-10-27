#include <iostream>

//Bottom-Up DP table 12-3

int getMinSteps ( int n )
{
    int dp[n+1], i;
    dp[1] = 0; // trivial case
    for( i = 2 ; i <= n ; i ++ )
    {
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = std::min( dp[i] , 1+ dp[i/2] );
        if(i%3==0) dp[i] = std::min( dp[i] , 1+ dp[i/3] );
    }
    return dp[n];
}


int main() {

    int testCases[] = {1, 4, 7, 10};

    // bottom up DP

    for (int n : testCases) {
        std::cout << "n = " << n << " - Min Steps: " << getMinSteps(n) << std::endl;

    }

    return 0;
}
