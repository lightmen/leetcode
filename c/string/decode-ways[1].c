int numDecodings(char* s) {
    int *dp;
    int len,i;
    int ret,value;

    len = strlen(s);
    if(len == 0)
        return 0;

    dp = (int *)malloc(sizeof(int) * (len + 1));
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;

    for(i = 2; i <= len; ++i){
        dp[i] = 0;
        if(s[i-1] != '0')
            dp[i] = dp[i-1];

        value = (s[i-2] - '0') * 10 + s[i-1] - '0';
        if(value >= 10 && value <= 26)
            dp[i] += dp[i-2];
    }

    ret = dp[len];
    free(dp);

    return ret;
}
