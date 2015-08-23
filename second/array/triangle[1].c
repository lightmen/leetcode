int minimumTotal(int **triangle, int numRows) {
    int *dp;
    int tmp,prev;
    int i,j,ret;

    dp = (int *)malloc(sizeof(int) * numRows);
    dp[0] = triangle[0][0];
    for(i = 1; i < numRows; ++i){
        prev = dp[0];
        dp[0] += triangle[i][0];
        for(j = 1; j < i; ++j){
            tmp = dp[j];
            dp[j] = prev < tmp ? prev : tmp;
            dp[j] += triangle[i][j];
            prev = tmp;
        }
        dp[i] = triangle[i][i] + prev;
    }

    ret = dp[0];
    for(i = 1; i < numRows; ++i)
        ret = dp[i] < ret ? dp[i] : ret;

    return ret;
}
