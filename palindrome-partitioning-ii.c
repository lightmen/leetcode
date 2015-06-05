int minCut(char* s) {
    int *dp;
    int **is_palin;
    int len = strlen(s);
    int i,j,ret;

    dp = (int *)malloc(sizeof(int) * (len+1));
    is_palin = (int **)malloc(sizeof(int *) * len);
    for(i = 0; i < len; ++i){
        is_palin[i] = (int *)malloc(sizeof(int) * len);
        memset(is_palin[i],0,sizeof(int) * len);
        is_palin[i][i] = 1;
    }

    dp[len] = -1;
    for(i = len - 1; i >= 0; --i){
        dp[i] = dp[i+1] + 1;
        for(j = i+1; j < len; ++j){
            if(s[i] == s[j]){
                if(j - i < 2 || is_palin[i+1][j-1]){
                    is_palin[i][j] = 1;
                    dp[i] = dp[j+1] + 1 < dp[i] ? dp[j+1] + 1 : dp[i];
                }
            }
        }
    }

    ret = dp[0];
    for(i = 0; i < len; ++i)
        free(is_palin[i]);
    free(is_palin);
    free(dp);

    return ret;
}
