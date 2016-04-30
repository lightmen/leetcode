int minSubArrayLen(int s, int* nums, int numsSize) {
    int ret = INT_MAX;
    int sum,cur;
    int i;

    sum = 0;
    cur = 0;
    for(i = 0; i < numsSize; ++i){
        cur++;
        sum += nums[i];
        while(sum >= s){
            ret = cur < ret ? cur : ret;
            sum -= nums[i - cur + 1];
            cur--;
        }
    }

    return ret == INT_MAX ? 0 : ret;
}
