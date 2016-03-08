int longestValidParentheses(char* s) {
    int *dp;
    int i,len,j,max_count;

    len = strlen(s);
    dp = (int *)malloc(sizeof(int) * (len + 1));
    dp[0] = 0;
    max_count = 0;

    for(i = 1; i <= len; ++i){
        j = i - dp[i-1] - 2;
        if(s[i-1] == '(' || j < 0 || s[j] != '('){
            dp[i] = 0;
        }else{
            dp[i] = dp[j] + dp[i-1] + 2;
            max_count = dp[i] > max_count ? dp[i] : max_count;
        }
    }

    free(dp);
    return max_count;
}
