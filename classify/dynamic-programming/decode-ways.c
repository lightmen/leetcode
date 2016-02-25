
int numDecodings(char* s) {
    int *dp;
    int i,len,value;

    len = strlen(s);
    if(len == 0)
        return 0;

    dp = (int *)malloc(sizeof(int) * (len + 1));
    dp[len] = 1;
    dp[len-1] = s[len-1] != '0' ? 1 : 0;
    for(i = len - 2; i >= 0; --i){
        if(s[i] == '0'){
            dp[i] = 0;
            continue;
        }

        dp[i] = dp[i+1];
        value = (s[i] - '0') * 10 + (s[i+1] - '0');
        if(value >= 10 && value <= 26)
            dp[i] += dp[i+2];
    }

    value = dp[0];
    free(dp);
    return value;
}
