int rob(int* nums, int numsSize) {
    int *dp0,*dp1;
    int i,ret;
    dp0 = (int *)malloc(sizeof(int) * (numsSize + 1));
    dp1 = (int *)malloc(sizeof(int) * (numsSize + 1));
    
    dp0[0] = 0;
    dp0[1] = nums[0];
    for(i = 2; i < numsSize; ++i)
        dp0[i] = (dp0[i-1] > dp0[i-2] + nums[i-1] ? 
            dp0[i-1] : dp0[i-2] + nums[i-1]);
    dp0[i] = dp0[i-1] > dp0[i-2] ? dp0[i-1] : dp0[i-2];
    
    dp1[0] = 0;
    dp1[1] = 0;
    for(i = 2; i <= numsSize; ++i)
        dp1[i] = (dp1[i-1] > dp1[i-2] + nums[i-1] ? 
                dp1[i-1] : dp1[i-2] + nums[i-1]);
                
    ret = dp0[numsSize] > dp1[numsSize] ? 
            dp0[numsSize] : dp1[numsSize];
    free(dp0);
    free(dp1);
    
    return ret;
}
