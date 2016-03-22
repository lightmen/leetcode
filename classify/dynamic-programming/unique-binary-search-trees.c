int numTrees(int n) {
    int *dp;
    int i,j;
    int ret;

    dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = 1;

    for(i = 1; i <= n; ++i){
        dp[i] = 0;
        for(j = 0; j < i; ++j)
            dp[i] += (dp[j] * dp[i-j-1]);
    }

    ret = dp[n];
    free(dp);
    return dp;
}
