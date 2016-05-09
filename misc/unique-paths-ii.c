int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int **dp;
    int i,j;

    dp = (int **)malloc(sizeof(int *) * obstacleGridRowSize);
    for(i = 0; i < obstacleGridRowSize; ++i)
        dp[i] = (int *)malloc(sizeof(int) * obstacleGridColSize);

    if(obstacleGrid[0][0])
        dp[0][0] = 0;
    else 
        dp[0][0] = 1;

    for(i = 1; i < obstacleGridRowSize; ++i)
        if(obstacleGrid[i][0])
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0];

    for(j = 1; j < obstacleGridColSize; ++j)
        if(obstacleGrid[0][j])
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j-1];
    
    for(i = 1; i < obstacleGridRowSize; ++i)
        for(j = 1; j < obstacleGridColSize; ++j){
            if(obstacleGrid[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        
    return dp[obstacleGridRowSize-1][obstacleGridColSize-1];
}
