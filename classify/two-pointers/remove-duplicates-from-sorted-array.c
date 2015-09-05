int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    int cur = 0;

    while(cur < numsSize){
        if(cur == 0 || nums[cur] != nums[cur-1])
            nums[count++] = nums[cur];
        ++cur;
    }

    return count;
}
