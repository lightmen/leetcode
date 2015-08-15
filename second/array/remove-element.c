int removeElement(int* nums, int numsSize, int val) {
    int count,i;

    count = 0;
    for(i = 0; i < numsSize; ++i){
        if(nums[i] != val)
            nums[count++] = nums[i];
    }

    return count;
}
