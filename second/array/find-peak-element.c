int findPeakElement(int* nums, int numsSize) {
    int i;
    for(i = 0; i < numsSize; ++i){
        if((i == 0 || nums[i] > nums[i-1])
            && (i == numsSize -1 || nums[i] > nums[i+1]))
            return i;
    }
}
