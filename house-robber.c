int rob(int num[], int n) {
    int *dp;
    int i,ret;
    dp = (int *)malloc(sizeof(int) * (n+1));
    dp[0] = 0;
    dp[1] = num[0];
    for(i = 2; i <= n; ++i)
        dp[i] = (dp[i-1] > (dp[i-2] + num[i-1])) ?
            dp[i-1] : dp[i-2] + num[i-1];
    ret = dp[n];

    free(dp);
    return ret;
}
