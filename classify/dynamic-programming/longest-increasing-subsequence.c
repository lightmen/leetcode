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
        for(j = i + 1; j < numsSize; ++j)
            if(nums[j] > nums[i])
                dp[j] = max_2(dp[j],dp[i] + 1);
    }


    ret = 0;
    for(i = 0; i < numsSize; ++i)
        if(dp[i] > ret)
            ret = dp[i];

    free(dp);
    return ret;
}
