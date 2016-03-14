int maxSubArray(int* nums, int numsSize) {
    int max_sum, cur_sum;
    int i;

    max_sum = nums[0];
    cur_sum = 0;
    for(i = 0; i < numsSize; ++i){
        cur_sum += nums[i];
        max_sum = cur_sum > max_sum ? cur_sum : max_sum;
        if(cur_sum < 0)
            cur_sum = 0;
    }

    return max_sum;
}
