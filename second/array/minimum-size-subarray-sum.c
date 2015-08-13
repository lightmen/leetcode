int minSubArrayLen(int s, int* nums, int numsSize) {
    int i,j;
    int sum;
    int count;
    int ret = numsSize + 1;

    i = 0;
    j = 0;
    sum = 0;
    count = 0;
    while(1){
        if(i < numsSize && sum >= s){
            if(count < ret)
                ret = count;
            sum -= nums[i++];
            count--;
        }else if(j < numsSize){
            sum += nums[j++];
            count++;
        }else{
            break;
        }
    }

    return ret == numsSize + 1 ? 0 : ret;
}
