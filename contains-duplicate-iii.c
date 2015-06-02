bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    int i,j;

    for(i = 0; i < numsSize; ++i){
        for(j = i;j < numsSize && j <= i + k; ++j)
            if(i != j && labs(nums[j] - nums[i]) <= t)
                return true;
    }
    
    return false;
}
