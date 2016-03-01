int max_2(int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    int *dp0, *dp1;
    int value;
    int i;

    dp0 = (int *)malloc(sizeof(int) * (numsSize + 1));
    dp1 = (int *)malloc(sizeof(int) * (numsSize + 1));

    dp0[0] = 0;
    dp0[1] = nums[0];
    for(i = 2; i < numsSize; ++i)
        dp0[i] = max_2(dp0[i-1], dp0[i-2] + nums[i-1]);

    if(numsSize > 1)
        dp0[numsSize] = dp0[numsSize - 1];

    dp1[0] = 0;
    dp1[1] = 0;
    for(i = 2; i <= numsSize; ++i)
        dp1[i] = max_2(dp1[i-1], dp1[i-2] + nums[i-1]);

    value = max_2(dp0[numsSize], dp1[numsSize]);

    free(dp0);
    free(dp1);

    return value;
}
