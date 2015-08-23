int minimumTotal(int **triangle, int numRows) {
    int *dp;
    int *tmp;
    int i,j,ret;

    dp = (int *)malloc(sizeof(int) * numRows);
    tmp = (int *)malloc(sizeof(int) * numRows);
    dp[0] = triangle[0][0];
    for(i = 1; i < numRows; ++i){
        memcpy(tmp,dp,sizeof(int) * i);
        memcpy(dp,triangle[i],sizeof(int) * (i + 1));
        dp[0] += tmp[0];
        for(j = 1; j < i; ++j){
            dp[j] += tmp[j] < tmp[j-1] ? tmp[j] : tmp[j-1];
        }
        dp[i] += tmp[i-1];
    }

    ret = dp[0];
    for(i = 1; i < numRows; ++i)
        ret = dp[i] < ret ? dp[i] : ret;

    free(tmp);
    free(dp);
    return ret;
}
