int minDistance(char* word1, char* word2) {
    int **dp;
    int len1,len2;
    int i,j,ret;

    len1 = strlen(word1);
    len2 = strlen(word2);

    dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for(i = 0; i <= len1; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        memset(dp[i],0,sizeof(int) * (len2+1));
    }

    for(i = 1; i <= len1; ++i)
        dp[i][0] = i;
    for(i = 1; i <= len2; ++i)
        dp[0][i] = i;

    for(i = 1; i <= len1; ++i){
        for(j = 1; j <= len2; ++j){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                ret = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                ret = dp[i-1][j-1] < ret ? dp[i-1][j-1] : ret;

                dp[i][j] = ret + 1;
            }
        }
    }

    ret = dp[len1][len2];
    for(i = 0; i <= len1; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
