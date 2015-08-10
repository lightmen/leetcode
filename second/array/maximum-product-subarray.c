int maxProduct(int* nums, int numsSize) {
    int ret;
    int i;
    int *min;
    int *max;

    min = (int *)malloc(sizeof(int) * numsSize);
    max = (int *)malloc(sizeof(int) * numsSize);

    memset(min,0,sizeof(int) * numsSize);
    memset(max,0,sizeof(int) * numsSize);

    min[0] = nums[0];
    max[0] = nums[0];

    for(i = 1; i < numsSize; ++i){
        if(nums[i] > 0){
            max[i] = (max[i-1] * nums[i] > nums[i]) ?
                max[i-1] * nums[i] : nums[i];
            min[i] = (min[i-1] * nums[i] < nums[i]) ?
                min[i-1] * nums[i] : nums[i];
        }else if(nums[i] < 0){
            max[i] = (min[i-1] * nums[i] > nums[i]) ?
                min[i-1] * nums[i] : nums[i];
            min[i] = (max[i-1] * nums[i] < nums[i]) ?
                max[i-1] * nums[i] : nums[i];
        }
    }

    ret = max[0];
    for(i = 1; i < numsSize; ++i)
        if(max[i] > ret)
            ret = max[i];

    free(min);
    free(max);
    return ret;
}
