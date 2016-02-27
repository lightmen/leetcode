int numDistinct(char* s, char* t) {
    int **dp;
    int i,j,len_s,len_t;
    int ret;

    len_s = strlen(s);
    len_t = strlen(t);

    dp = (int **)malloc(sizeof(int *) * (len_s + 1));
    for(i = 0; i <= len_s; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (len_t + 1));
        memset(dp[i], 0, sizeof(int) * (len_t + 1));
        dp[i][0] = 1;
    }

    for(i = 1; i <= len_s; ++i){
        for(j = 1; j <= len_t; ++j){
            dp[i][j] = dp[i-1][j];
            if(s[i-1] == t[j-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }

    ret = dp[len_s][len_t];
    for(i = 0; i <= len_s; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
