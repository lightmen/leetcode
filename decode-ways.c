int numDecodings(char *s) {
    int i,len;
    //int *dp = NULL;
    int dp[5000];
    len = strlen(s);
    
    //dp = (int *)malloc(sizeof(int) * (len+1));
    //if(dp == NULL)
     //   return len;
    dp[len-1] = s[len-1] == '0' ? 0 : 1;
    dp[len] = 1;
    
    for(i = len-2; i >= 0; --i){
        if(s[i] == '0')
            dp[i] = 0;
        else if(((s[i] - '0') * 10 + (s[i+1] - '0')) > 26)
            dp[i] = dp[i+1];
        else
            dp[i] = dp[i+1] + dp[i+2];
    }
    return dp[0];
}
