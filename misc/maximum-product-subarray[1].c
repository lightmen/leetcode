static inline int min(int a, int b)
{
    return a < b ? a : b;
}
static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maxProduct(int* nums, int numsSize) {
    int i,cur_min,cur_max,ret,tmp_min,tmp_max;

    ret = cur_min = cur_max = nums[0];
    for(i = 1; i < numsSize; ++i){
        tmp_max = max(nums[i], max(cur_max * nums[i], cur_min*nums[i]));
        tmp_min = min(nums[i], min(cur_max * nums[i], cur_min*nums[i]));
        
        cur_max = tmp_max;
        cur_min = tmp_min;
        ret = max(cur_max,ret);
    }
    
    return ret;
}
