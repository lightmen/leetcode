int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int **dp;
    int i,j;
    int ret;

    dp = malloc(sizeof(int *) * obstacleGridRowSize);
    for(i = 0; i < obstacleGridRowSize; ++i)
        dp[i] = malloc(sizeof(int) * obstacleGridColSize);

    dp[0][0] = ((obstacleGrid[0][0] == 1) ? 0 : 1);
    for(i = 1; i < obstacleGridRowSize; ++i)
        dp[i][0] = (dp[i-1][0] != 0 && obstacleGrid[i][0] != 1) ? 1 : 0;
    for(j = 1; j < obstacleGridColSize; ++j)
        dp[0][j] = (dp[0][j-1] != 0 && obstacleGrid[0][j] != 1) ? 1 : 0;

    for(i = 1; i < obstacleGridRowSize; ++i)
        for(j = 1; j < obstacleGridColSize; ++j)
            dp[i][j] = ((obstacleGrid[i][j] == 1) ? 0 : (dp[i-1][j] + dp[i][j-1]));

    ret = dp[obstacleGridRowSize-1][obstacleGridColSize-1];
    for(i = 0; i < obstacleGridRowSize; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
