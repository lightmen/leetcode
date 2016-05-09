int numDistinct(char* s, char* t) {
    int lens = strlen(s);
    int lent = strlen(t);
    int **dp;
    int i,j;
    int ret;

    dp = (int **)malloc(sizeof(int *) * (lens+1));
    for(i = 0; i <= lens; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (lent + 1));
        memset(dp[i],0,sizeof(int) * (lent+1));
    }

    for(i = 0; i <= lens; ++i){
        dp[i][0] = 1;
    }

    for(i = 1; i <= lens; ++i){
        for(j = 1; j <= lent; ++j){
            dp[i][j] += dp[i-1][j];
            if(s[i-1] == t[j-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }

    ret = dp[lens][lent];

    for(i = 0; i <= lens; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
