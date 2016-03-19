#define min_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : _y; \
})

int minCut(char* s) {
    int i,j;
    int len;
    int *dp;
    int **p;
    int ret;

    len = strlen(s);
    dp = (int *)malloc(sizeof(int) * (len + 1));
    p = (int **)malloc(sizeof(int *) * len);
    for(i = 0; i < len; ++i){
        p[i] = (int *)malloc(sizeof(int) * len);
        memset(p[i], 0, sizeof(int) * len);
        p[i][i] = 1;
    }

    dp[len] = -1;
    for(i = len-1; i >= 0; --i){
        dp[i] = dp[i+1] + 1;
        for(j = i+1; j <= len-1; ++j){
            if(s[i] == s[j] && (j - i < 2 || p[i+1][j-1])){
                p[i][j] = 1;
                dp[i] = min_2(dp[i], 1 + dp[j+1]);
            }
        }
    }

    ret = dp[0];

    free(dp);
    for(i = 0; i < len; ++i)
        free(p[i]);
    free(p);

    return ret;
}
