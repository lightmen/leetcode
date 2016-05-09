bool isInterleave(char* s1, char* s2, char* s3) {
    bool **dp;
    bool ret;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int i,j;

    if(len1 + len2 != len3)
        return false;
    
    dp = (bool **)malloc(sizeof(bool *) * (len1 + 1));
    for(i = 0; i <= len1; ++i)
        dp[i] = (bool *)malloc(sizeof(bool) * (len2 + 1));
        
    dp[0][0] = true;
    for(i = 1; i <= len1; ++i)
        dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i-1]);
    for(j = 1; j <= len2; ++j)
        dp[0][j] = (dp[0][j-1] && s2[j-1] == s3[j-1]);
        
    for(i = 1; i <= len1; ++i)
        for(j = 1; j <= len2; ++j){
            dp[i][j] = ((dp[i-1][j] && s1[i-1] == s3[i+j-1])  || 
                (dp[i][j-1] && s2[j-1] == s3[i+j-1]));
        }
     
    ret = dp[len1][len2];
    for(i = 0; i <= len1; ++i)
        free(dp[i]);
    free(dp);
    return ret;
}
