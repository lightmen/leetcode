bool isMatch(char* s, char* p) {
    int lens,lenp;
    int i,j;
    int **dp;
    int ret;

    lens = strlen(s);
    lenp = strlen(p);

    dp = malloc(sizeof(int *) * (lens + 1));
    for(i = 0; i <= lens; ++i){
        dp[i] = malloc(sizeof(int) * (lenp + 1));
        dp[i][0] = 0;
    }
    dp[0][0] = 1;

    for(i = 1; i <= lenp; ++i)
        dp[0][i] = dp[0][i-1] && (p[i-1] == '*');

    for(i = 1; i <= lens; ++i){
        for(j = 1; j <= lenp; ++j){
            if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }else if(p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1]);
            }
        }
    }

    ret = dp[lens][lenp];
    for(i = 0; i <= lens; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
