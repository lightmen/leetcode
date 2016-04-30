int minDistance(char* word1, char* word2) {
    int **dp;
    int len1,len2;
    int i,j,value;

    len1 = strlen(word1);
    len2 = strlen(word2);

    if(len1 == 0 || len2 == 0)
        return len1 == 0 ? len2 : len1;

    dp = (int **)malloc(sizeof(int *) * (len1+1));
    for(i = 0; i <= len1; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        memset(dp[i],0,sizeof(int) * (len2 + 1));
    }

    for(i = 1; i <= len1; ++i)
        dp[i][0] = i;
    for(j = 1; j <= len2; ++j)
        dp[0][j] = j;

    for(i = 1; i <= len1; ++i){
        for(j = 1; j <= len2; ++j){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }

            /* dp[i-1][j-1]: repleace a char
             * dp[i][j-1]: insert a char after word1[i]
             * dp[i-1][j]: delet the char word1[i]
             */
            value = dp[i][j-1] < dp[i-1][j-1] ? dp[i][j-1] : dp[i-1][j-1];
            value = dp[i-1][j] < value ? dp[i-1][j] : value;

            dp[i][j] = value + 1;
        }
    }

    value = dp[len1][len2];
    for(i = 0; i <= len1; ++i)
        free(dp[i]);
    free(dp);

    return value;
}
