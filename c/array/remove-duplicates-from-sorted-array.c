int removeDuplicates(int* nums, int numsSize) {
    int count,i;

    if(numsSize == 0)
        return 0;

    count = 1;
    for(i = 1; i < numsSize; ++i){
        if(nums[i] != nums[count-1])
            nums[count++] = nums[i];
    }

    return count;
}
