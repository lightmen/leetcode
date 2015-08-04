int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;

    while(i < numsSize){
        if(nums[i] <= 0 || nums[i] >= numsSize || nums[i] == i + 1
                || nums[i] == nums[nums[i] - 1]){
            ++i;
        }else{
            int tmp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[tmp-1] = tmp;
        }
    }

    for(i = 0; i < numsSize; ++i)
        if(nums[i] != i + 1)
            break;

    return i + 1;
}
