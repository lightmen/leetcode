int threeSumClosest(int* nums, int numsSize, int target) {
    int i,j,k;
    int m,sum,ab;
    m = INT_MAX;
    for(i = 0; i < numsSize; ++i)
        for(j = i + 1; j < numsSize; ++j)
            for(k = j + 1; k < numsSize; ++k){
                ab = abs(nums[i]+ nums[j] + nums[k] - target);
                if(ab < m){
                    m = ab;
                    sum = nums[i] + nums[j] + nums[k];
                }
                if(ab == 0)
                    return sum;
            }
            
    return sum;
}
