int removeDuplicates(int* nums, int numsSize) {
    int i,count;

    count = 1;
    for(i = 2; i < numsSize; ++i)
        if(nums[i] != nums[count-1])
            nums[++count] = nums[i];

    return numsSize < 2 ? numsSize : count+1;
}
