int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize) {
    int **dp;
    int i,j,value;

    dp = (int **)malloc(sizeof(int *) * dungeonRowSize);
    for(i = 0; i < dungeonRowSize; ++i){
        dp[i] = (int *)malloc(sizeof(int) * dungeonColSize);
        memset(dp[i], 0, sizeof(int) * dungeonColSize);
    }

    dp[dungeonRowSize-1][dungeonColSize-1] = dungeon[dungeonRowSize-1][dungeonColSize-1] < 0 ?
        - dungeon[dungeonRowSize-1][dungeonColSize-1] : 0;

    for(j = dungeonColSize - 2; j >= 0; --j)
        dp[dungeonRowSize-1][j] =  max(dp[dungeonRowSize-1][j+1] - dungeon[dungeonRowSize-1][j],0);

    for(i = dungeonRowSize - 2; i >= 0; --i)
        dp[i][dungeonColSize-1] =  max(dp[i+1][dungeonColSize-1] - dungeon[i][dungeonColSize-1],0);

    for(i = dungeonRowSize - 2; i >= 0; --i){
        for(j = dungeonColSize - 2; j >= 0; --j){
            value = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(value - dungeon[i][j],0);
        }
    }

    value = dp[0][0] + 1;

    for(i = 0; i < dungeonRowSize; ++i)
        free(dp[i]);
    free(dp);

    return value;
}
