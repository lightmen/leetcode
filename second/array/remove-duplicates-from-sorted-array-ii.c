int removeDuplicates(int* nums, int numsSize) {
    int count,i;

    if(numsSize <= 2)
        return numsSize;

    count = 2;
    for(i = 2; i < numsSize; ++i){
        if(nums[i] != nums[count-2])
            nums[count++] = nums[i];
    }

    return count;
}
