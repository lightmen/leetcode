int maxSubArray(int* nums, int numsSize) {
    int ret = nums[0];
    int i,sum;
    sum = 0;
    for(i = 0; i < numsSize; ++i){
        sum += nums[i];
        ret = sum > ret ? sum : ret;
        sum = sum > 0 ? sum : 0;
    }

    return ret;
}
