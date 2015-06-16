int numDistinct(char* s, char* t) {
    int lens = strlen(s);
    int lent = strlen(t);
    int **dp;
    int i,j;
    int ret;

    dp = (int **)malloc(sizeof(int *) * (lent+1));
    for(i = 0; i <= lent; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (lens + 1));
        memset(dp[i],0,sizeof(int) * (lens+1));
    }

    for(j = 0; j <= lens; ++j){
        dp[0][j] = 1;
    }

    for(i = 1; i <= lent; ++i){
        for(j = 1; j <= lens; ++j){
            dp[i][j] += dp[i][j-1];
            if(t[i-1] == s[j-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }

    ret = dp[lent][lens];

    for(i = 0; i <= lent; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
