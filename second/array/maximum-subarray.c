int maxSubArray(int* nums, int numsSize) {
    int i;
    int ret = nums[0];
    int cur = 0;

    for(i = 0; i < numsSize; ++i){
        cur += nums[i];
        ret = cur > ret ? cur : ret;
        cur = cur > 0 ? cur : 0;
    }

    return ret;
}
