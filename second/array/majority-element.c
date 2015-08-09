int majorityElement(int* nums, int numsSize) {
    int count;
    int ret;
    int i;

    count = 0;
    for(i = 0; i < numsSize; ++i){
        if(count == 0)
            ret = nums[i];
        if(ret == nums[i])
            count++;
        else
            count--;
    }

    return ret;
}
