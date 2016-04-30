#define min_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : _y; \
})


int numSquares(int n) {
    int ret;
    int i,j;
    int *dp;

    dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = 0;
    dp[1] = 1;

    for(i = 2; i <= n; ++i){
        dp[i] = i;
        for(j = 1; j*j <= i; ++j)
            dp[i] = min_2(1 + dp[i-j*j], dp[i]);
    }

    ret = dp[n];
    free(dp);
    return ret;
}
