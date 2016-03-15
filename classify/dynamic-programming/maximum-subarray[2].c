#define max_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x > _y ? _x : _y; \
})

int maxSubArray(int* nums, int numsSize) {
    int *sum;
    int i,ret;

    sum = (int *)malloc(sizeof(int) * numsSize);
    sum[0] = nums[0];
    for(i = 1; i < numsSize; ++i)
        sum[i] = max_2(nums[i], nums[i] + sum[i-1]);

    ret = INT_MIN;
    for(i = 0; i < numsSize; ++i)
        ret = max_2(sum[i], ret);

    free(sum);
    return ret;
}
