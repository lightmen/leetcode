int max_2(int a, int b)
{
    return a > b ? a : b;
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int **dp;
    int i,j,max_square,min_value;

    dp = (int **)malloc(sizeof(int *) * (matrixRowSize + 1));
    for(i = 0; i <= matrixRowSize; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (matrixColSize + 1));
        memset(dp[i], 0, sizeof(int) * (matrixColSize + 1));
    }

    for(i = 1; i <= matrixRowSize; ++i)
        for(j = 1; j <= matrixColSize; ++j){
            min_value = dp[i-1][j] < dp[i-1][j-1] ? dp[i-1][j] : dp[i-1][j-1];
            min_value = dp[i][j-1] < min_value ? dp[i][j-1] : min_value;
            if(matrix[i-1][j-1] == '1')
                dp[i][j] = min_value + 1;
        }

    max_square = 0;
    for(i = 1; i <= matrixRowSize; ++i)
        for(j = 1; j <= matrixColSize; ++j)
            max_square = max_2(max_square,dp[i][j] * dp[i][j]);

    for(i = 0; i <= matrixRowSize; ++i)
        free(dp[i]);
    free(dp);

    return max_square;
}
