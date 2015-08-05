bool canJump(int* nums, int numsSize) {
    int i = 0;
    int max_jump = nums[0];

    while(max_jump < numsSize-1){
        int max = max_jump;
        for(; i <= max_jump; ++i)
            if(i + nums[i] > max)
                max = i + nums[i];
        if(max_jump == max)
            return false;
        max_jump = max;
    }

    return true;
}
