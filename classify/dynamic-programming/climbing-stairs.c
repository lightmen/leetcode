int climbStairs(int n) {
    int *dp;
    int i,ret;

    dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = 1;
    dp[1] = 1;
    for(i = 2; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];

    ret = dp[n];
    free(dp);
    return ret;
}
