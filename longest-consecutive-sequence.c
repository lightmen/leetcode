static int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int longestConsecutive(int* nums, int numsSize) {
    int max = 1;
    int i;
    int cur = 1;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i = 1; i < numsSize; ++i){
        if(nums[i] == nums[i-1]+1){
            cur++;
            if(cur > max)
                max = cur;
        }else if(nums[i] != nums[i-1]){
            cur = 1;
        }
    }
    return max;
}
