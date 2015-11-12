int numDecodings(char* s) {
    int len;
    int *dp;
    int i,value;
    int ret;

    len = strlen(s);
    if(len == 0)
        return 0;

    dp = (int *)malloc(sizeof(int) * (len+1));

    dp[len] = 1;
    dp[len-1] = s[len-1] == '0' ? 0 : 1;

    for(i = len - 2; i >= 0; --i){
        if(s[i] == '0')
            dp[i] = 0;
        else if((s[i] - '0') * 10 + (s[i+1] - '0') <= 26)
            dp[i] = dp[i+1] + dp[i+2];
        else
            dp[i] = dp[i+1];
    }

    ret = dp[0];
    free(dp);
    return ret;
}
