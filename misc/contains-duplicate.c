tatic int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
bool containsDuplicate(int* nums, int numsSize) {
    int i;
    qsort(nums,numsSize,sizeof(int),cmp);
    i = 1;
    while(i < numsSize){
        if(nums[i] == nums[i-1])
            return true;
        ++i;
    }
    return false;
}
