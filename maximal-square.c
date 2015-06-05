int maximalSquare(char** matrix, int row, int col) {
    int **dp;
    int i,j;
    int ret,min;

    dp = (int **)malloc(sizeof(int *) * row);
    for(i = 0; i < row; ++i){
        dp[i] = (int *)malloc(sizeof(int) * col);
        memset(dp[i],0,sizeof(int) * col);
    }

    ret = 0;
    for(i = 0; i < row; ++i){
        for(j = 0; j < col; ++j){
            if(i-1 < 0 || j-1 < 0 || matrix[i][j] == '0')
                min = 0;
            else{
                min = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                min = dp[i-1][j-1] < min ? dp[i-1][j-1] : min;
            }

            if(matrix[i][j] == '1')
                min++;

            dp[i][j] = min;

            if(min * min > ret)
                ret = min * min;
        }
    }
    
    for(i = 0; i < row; ++i)
        free(dp[i]);
    free(dp);
    
    return ret;
}
