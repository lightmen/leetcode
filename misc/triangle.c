int minimumTotal(int **triangle, int numRows) {
    int **dp;
    int i,j,k,m;
    dp = (int **)malloc(sizeof(int *) * numRows);
    for(k = 1; k <= numRows; ++k)
        dp[k-1] = (int *)malloc(sizeof(int *) * k);

    dp[0][0] = triangle[0][0];
    for(i = 1; i < numRows; ++i){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for(j = 1; j < i; ++j){
            m = dp[i-1][j-1] < dp[i-1][j] ? dp[i-1][j-1] 
                        : dp[i-1][j];
            dp[i][j] = m + triangle[i][j];
        }
        dp[i][j] = dp[i-1][j-1] + triangle[i][j];
    }
    
    m = dp[numRows-1][0];
    for(i = 1; i < numRows; ++i)
        if(dp[numRows-1][i] < m)
            m = dp[numRows-1][i];
            
    for(i = 0; i < numRows; ++i)
        free(dp[i]);
    free(dp);

    return m;
}
