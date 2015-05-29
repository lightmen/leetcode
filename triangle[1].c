int minimumTotal(int **triangle, int numRows) {
    int *dp;
    int i,j,m,prev;

    dp = (int *)malloc(sizeof(int) * numRows);

    dp[0] = triangle[0][0];
    for(i = 1; i < numRows; ++i){
        prev = dp[0] + triangle[i][0];
        for(j = 1; j < i; ++j){
            m = dp[j-1] < dp[j] ? dp[j-1] : dp[j];
            m += triangle[i][j];
            
            dp[j-1] = prev;
            prev = m;
        }
        m = dp[j-1] + triangle[i][j];
        dp[j-1] = prev;
        dp[j] = m;
    }
    
    m = dp[0];
    for(i = 1; i < numRows; ++i)
        if(dp[i] < m)
            m = dp[i];

    free(dp);

    return m;
}
