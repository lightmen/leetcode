bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i,j;
    for(i = 0; i < numsSize; ++i){
        for(j = i + 1; j <= i + k && j < numsSize; ++j)
            if(nums[i] == nums[j])
                return true;
    }

    return false;
}
