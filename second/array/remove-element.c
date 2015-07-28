int removeElement(int* nums, int numsSize, int val) {
    int ret = 0;
    int cur = 0;

    while(cur < numsSize){
        if(nums[cur] != val)
            nums[ret++] = nums[cur];
        cur++;
    }

    return ret;
}
