int max_2(int a, int b)
{
    return a > b ? a : b;
}

int lengthOfLIS(int* nums, int numsSize) {
    int *dp;
    int i,j;
    int ret;

    dp = (int *)malloc(sizeof(int) * numsSize);

    for(i = 0; i < numsSize; ++i)
        dp[i] = 1;

    for(i = 0; i < numsSize; ++i){
        for(j = 0; j < i; ++j)
            if(nums[i] > nums[j])
                dp[i] = max_2(dp[i],dp[j] + 1);
    }

    ret = 0;
    for(i = 0; i < numsSize; ++i)
        if(dp[i] > ret)
            ret = dp[i];

    free(dp);
    return ret;
}
