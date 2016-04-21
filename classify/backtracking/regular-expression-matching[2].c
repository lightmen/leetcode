bool isMatch(char* s, char* p) {
    int **dp;
    int len_s,len_p;
    int i,j;
    int ret;

    len_s = strlen(s);
    len_p = strlen(p);

    dp = malloc(sizeof(int *) * (len_s + 1));
    for(i = 0; i <= len_s; ++i){
        dp[i] = malloc(sizeof(int) * (len_p + 1));
        memset(dp[i], 0, sizeof(int) * (len_p + 1));
    }

    dp[0][0] = 1;
    for(i = 0; i <= len_s; ++i){
        for(j = 1; j <= len_p; ++j){
            if(p[j-1] != '.' && p[j-1] != '*'){
                dp[i][j] = (i > 0 && dp[i-1][j-1] && s[i-1] == p[j-1]);
            }else if(p[j-1] == '.'){
                dp[i][j] = (i > 0 && dp[i-1][j-1]);
            }else if(j > 1){
                if(dp[i][j-2] || dp[i][j-1]) //match 0 or 1 char
                    dp[i][j] = 1;
                else if(i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j])
                    dp[i][j] = 1;
            }
        }
    }

    ret = dp[len_s][len_p];
    for(i = 0; i <= len_s; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}
