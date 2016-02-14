int maxSubArray(int* nums, int numsSize) {
    int i, ret, sum;

    sum = 0;
    ret = INT_MIN;
    for(i = 0; i < numsSize; ++i){
        sum += nums[i];
        ret = sum > ret ? sum : ret;
        sum = sum > 0 ? sum : 0;
    }

    return ret;
}
