int climbStairs(int n) {
    int dp[n+1];
    int i;
    dp[0] = 0;
    
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
        
    dp[1] = 1;
    dp[2] = 2;
    for(i=3; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
        
    return dp[n];
}
