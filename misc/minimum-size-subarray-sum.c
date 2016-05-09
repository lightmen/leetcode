int minSubArrayLen(int s, int* nums, int numsSize) {
    int ret = numsSize + 1;
    int i,j;
    int sum = 0;
    i = j = 0;

    while(j < numsSize){
        sum += nums[j];
        while(sum >= s){
            if(j - i + 1 < ret)
                ret = j - i + 1;
            sum -= nums[i];
            i++;
        }
        j++;
    }

    return (ret == (numsSize + 1)) ? 0 : ret;
}
