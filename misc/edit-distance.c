int min_3(int a, int b, int c)
{
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int minDistance(char* word1, char* word2) {
    int **dp;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int i,j;
    int ret;

    dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for(i = 0; i <= len1; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }
    
    for(i = 0; i <= len1; ++i)
        dp[i][0] = i;
    for(j = 0; j <= len2; ++j)
        dp[0][j] = j;

    for(i = 1; i <= len1; ++i){
        for(j = 1; j <= len2; ++j){
            dp[i][j] = min_3(dp[i-1][j] + 1, dp[i][j-1] + 1, 
                dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
        }
    }
    
    ret = dp[len1][len2];

    for(i = 0; i <= len1; ++i)
        free(dp[i]);
    free(dp);
    
    return ret;
}
