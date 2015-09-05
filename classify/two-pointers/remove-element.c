int removeElement(int* nums, int numsSize, int val) {
    int count = -1;
    int i;

    for(i = 0; i < numsSize; ++i)
        if(nums[i] != val)
            nums[++count] = nums[i];

    return count+1;
}
