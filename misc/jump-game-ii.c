int jump(int* nums, int numsSize) {
    int i,cur_pos,max_pos;
    int ret;
    
    ret = 0;
    cur_pos = 0;
    max_pos = 0;

    for(i = 0; i < numsSize; ++i){
        if(cur_pos < i){
            ret++;
            cur_pos = max_pos;
        }
        max_pos = nums[i]+i > max_pos ? nums[i]+i : max_pos;
    }
    
    return ret;
}
