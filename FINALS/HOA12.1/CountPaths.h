template <int M, int N>
int countPaths(int (&cost)[M][N], int i, int j, int remaining){
    if (i >= M || j >= N)
        return 0;

    remaining -= cost[i][j];

    if (remaining < 0)
        return 0;

    if (i == M - 1 && j == N - 1) {
        return (remaining == 0) ? 1 : 0;
    }

    return countPaths(cost, i, j+1, remaining) + countPaths(cost, i+1, j, remaining);
}


