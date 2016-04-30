#define min_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : _y; \
})

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int **dp;
    int i,j,ret;

    dp = (int **)malloc(sizeof(int *) * gridRowSize);
    for(i = 0; i < gridRowSize; ++i)
        dp[i] = (int *)malloc(sizeof(int) * gridColSize);

    dp[0][0] = grid[0][0];
    for(i = 1; i < gridRowSize; ++i)
        dp[i][0] = grid[i][0] + dp[i-1][0];

    for(j = 1; j < gridColSize; ++j)
        dp[0][j] = grid[0][j] + dp[0][j-1];

    for(i = 1; i < gridRowSize; ++i)
        for(j = 1; j < gridColSize; ++j)
            dp[i][j] = min_2(dp[i-1][j], dp[i][j-1]) + grid[i][j];

    ret = dp[gridRowSize-1][gridColSize-1];

    for(i = 0; i < gridRowSize; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
