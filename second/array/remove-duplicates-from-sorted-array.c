int removeDuplicates(int* nums, int numsSize) {
    int count,j;

    if(numsSize == 0)
        return 0;

    count = 1;
    for(j = 1; j < numsSize; ++j){
        if(nums[j] == nums[j-1])
            continue;
        nums[count++] = nums[j];
    }

    return count;
}
