int removeDuplicates(int* nums, int numsSize) {
    int i,count = 0;

    if(numsSize == 0)
        return 0;

    for(i = 0; i < numsSize; ++i)
        if(nums[i] != nums[count])
            nums[++count] = nums[i];

    return count+1;
}
