#define min_3(x, y, z) ({ \
    int _x = (x); \
    int _y = (y); \
    int _z = (z); \
    int _min = _x < _y ? _x : _y; \
    _z < _min ? _z : _min; \
})

int nthUglyNumber(int n) {
    int *dp;
    int ret;
    int t2,t3,t5;
    int c;

    dp = (int *)malloc(sizeof(int) * n);
    dp[0] = 1;
    t2 = t3 = t5 = 0;
    c = 1;

    while(c < n){
        int tmp = min_3(dp[t2] * 2, dp[t3] * 3, dp[t5] * 5);
        dp[c++] = tmp;

        if(dp[t2] * 2 == tmp)
            t2++;
        if(dp[t3] * 3 == tmp)
            t3++;
        if(dp[t5] * 5 == tmp)
            t5++;
    }

    ret = dp[n-1];
    free(dp);
    return ret;
}
