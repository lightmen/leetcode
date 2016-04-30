int jump(int* nums, int numsSize) {
    int ret = 0;
    int i;
    int cur_pos,max_pos;

    cur_pos = 0;
    max_pos = 0;
    for(i = 0; i < numsSize; ++i){
        if(cur_pos < i){
            ret++;
            cur_pos = max_pos;
        }
        if(nums[i] + i > max_pos)
            max_pos = nums[i] + i;
    }

    return ret;
}
