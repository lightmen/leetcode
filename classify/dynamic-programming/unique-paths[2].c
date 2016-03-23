int uniquePaths(int m, int n) {
    int *dp;
    int i,j;
    int ret;

    dp = malloc(sizeof(int) * n);
    for(i = 0; i < n; ++i)
        dp[i] = 1;

    for(i = 1; i < m; ++i)
        for(j = 1; j < n; ++j)
            dp[j] += dp[j-1];

    ret = dp[n-1];
    free(dp);
    return ret;
}
