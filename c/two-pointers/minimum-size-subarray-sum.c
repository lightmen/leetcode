int minSubArrayLen(int s, int* nums, int numsSize) {
    int ret = numsSize + 1;
    int start = 0;
    int end = 0;
    int sum = 0;

    while(end < numsSize){
        sum += nums[end++];
        while(sum >= s){
            ret = (end - start) < ret ? (end - start) : ret;
            sum -= nums[start++];
        }
    }

    return ret == numsSize + 1 ? 0 : ret;
}
