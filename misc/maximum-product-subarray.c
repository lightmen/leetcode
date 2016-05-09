int maxProduct(int* nums, int numsSize) {
    int *min,*max;
    int i;
    int ret = nums[0];
    min = (int *)malloc(sizeof(int) * numsSize);
    max = (int *)malloc(sizeof(int) * numsSize);
    
    min[0] = max[0] = nums[0];
    for(i = 1; i < numsSize; ++i){
        min[i] = max[i] = nums[i];
        if(nums[i] > 0){
            max[i] = max[i] > max[i-1] * nums[i] ? max[i] : max[i-1] * nums[i];
            min[i] = min[i] < min[i-1] * nums[i] ? min[i] : min[i-1] * nums[i];
        }else if(nums[i] < 0){
            max[i] = max[i] > min[i-1] * nums[i] ? max[i] : min[i-1] * nums[i];
            min[i] = min[i] < max[i-1] * nums[i] ? min[i] : max[i-1] * nums[i];
        }
        if(max[i] > ret)
            ret = max[i];
    }
    
    free(max);
    free(min);
    return ret;
}
