int rob(int* nums, int numsSize) {
    int *dp;
    int i,value;

    dp = (int *)malloc(sizeof(int) * (numsSize + 1));
    dp[0] = 0;
    dp[1] = nums[0];
    for(i = 2; i <= numsSize; ++i)
        dp[i] = dp[i-2] + nums[i-1] > dp[i-1] ? dp[i-2] + nums[i-1] : dp[i-1];

    value = dp[numsSize];
    free(dp);
    return value;
}
