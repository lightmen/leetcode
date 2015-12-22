int lengthOfLIS(int* nums, int numsSize) {
    int *dp;
    int i,j;
    int max = 0;

    dp = (int *)malloc(sizeof(int) * numsSize);
    for(i = 0; i < numsSize; ++i){
        dp[i] = 1;
        for(j = 0; j < i; ++j)
            if(nums[j] < nums[i])
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
    }

    for(i = 0; i < numsSize; ++i)
        if(dp[i] > max)
            max = dp[i];

    free(dp);
    return max;
}
