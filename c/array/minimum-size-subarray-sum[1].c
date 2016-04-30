int minSubArrayLen(int s, int* nums, int numsSize) {
    int i,j;
    int sum;
    int ret = numsSize + 1;

    sum = 0;
    j = 0;
    for(i = 0; i < numsSize; ++i){
        while(j < numsSize && sum < s){
            sum += nums[j++];
        }

        if(sum >= s)
            ret = j - i < ret ? j - i : ret;
        sum -= nums[i];
    }

    return ret == numsSize + 1 ? 0 : ret;
}
