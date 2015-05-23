char* longestPalindrome(char* s) {
    int i,j,len;
    int dp[1000][1000];
    int max,index;
    char *ret;

    len = strlen(s);
    for(i = 0; i < len; ++i){
        memset(dp[i],0,sizeof(int) * len);
    }
    
    for(i = 0; i < len; ++i){
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1])
            dp[i][i+1] = 1;
    }
    
    for(i = 2; i < len; ++i){
        for(j = 0; j+i < len; ++j){
            if(s[j] == s[j+i] && dp[j+1][j+i-1])
                dp[j][j+i] = 1;
        }
    }
    
    max = 0;
    index = -1;
    for(i = 0; i < len; ++i) {
        for(j = i;j < len; ++j)
            if(dp[i][j] && j - i + 1 > max){
                max = j - i + 1;
                index = i;
            }
    }
    
    ret = (char *)malloc(sizeof(char) * (max + 1));
    i = 0;
    while(i < max){
        ret[i] = s[i+index];
        ++i;
    }
    ret[max] = '\0';

    return ret;
}
