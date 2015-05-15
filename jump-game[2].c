bool canJump(int* nums, int numsSize) {
    int i,max_pos;
    
    max_pos = 0;
    for(i = 0; i < numsSize; ++i){
        max_pos = nums[i]+i > max_pos ? nums[i]+i : max_pos;
        if(max_pos <= i)
            break;
    }
    
    if(max_pos >= (numsSize-1))
        return true;
    return false;
}
