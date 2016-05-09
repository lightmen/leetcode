int uniquePaths(int m, int n) {
    int **dp;
    int i,j;
    
    dp = (int **)malloc(sizeof(int *) * (m+1));
    for(i = 0; i <= m; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (n+1));
        memset(dp[i],0,sizeof(int)*(n+1));
    }
    dp[1][1] = 1;
    for(i = 1; i <= m; ++i)
        for(j = 1; j <= n; ++j)
            dp[i][j] += dp[i][j-1] + dp[i-1][j];
            
    return dp[m][n];
}
