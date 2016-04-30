#define max_2(x, y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x > _y ? _x : _y; \
})

//DP
int maxSubArray(int* nums, int numsSize) {
    int cur_sum,pre_sum;
    int max_value;
    int i;

    cur_sum = nums[0];
    max_value = nums[0];
    for(i = 1; i < numsSize; ++i){
        pre_sum = cur_sum;
        cur_sum = max_2(nums[i], nums[i] + pre_sum);
        max_value = max_2(cur_sum, max_value);
    }

    return max_value;
}
