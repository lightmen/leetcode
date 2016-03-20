#define min_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : y; \
})

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int i,j,prev,tmp;
    int *dp;
    int ret;
    int max_num;

    max_num = triangleColSizes[triangleRowSize-1];
    dp = (int *)malloc(sizeof(int) * max_num);
    for(j = 0; j < triangleColSizes[0]; ++j)
        dp[j] = triangle[0][j];

    for(i = 1; i < triangleRowSize; ++i){
        prev = dp[0];
        dp[0] += triangle[i][0];
        for(j = 1; j < triangleColSizes[i] - 1; ++j){
            tmp = dp[j];
            dp[j] = min_2(prev, dp[j]) + triangle[i][j];
            prev = tmp;
        }
        dp[j] = prev +  triangle[i][j];
    }

    ret = dp[0];
    for(j = 1; j < max_num; ++j)
        ret = min_2(ret, dp[j]);

    free(dp);
    return ret;
}
