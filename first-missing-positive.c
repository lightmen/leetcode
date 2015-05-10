static void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
int firstMissingPositive(int* nums, int numsSize) {
    int i;
    for(i = 0; i < numsSize;){
        if(nums[i] <= 0 || nums[i] == i + 1 || 
        nums[i] > numsSize || nums[i] == nums[nums[i]-1])
            i++;
        else
            swap(&nums[i],&nums[nums[i]-1]);
    }
    
    for(i = 0; i < numsSize; ++i)
        if(nums[i] != i+1)
            break;
    return i + 1;
}
