static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);

    for(int i = 1; i < numsSize; ++i)
        if(nums[i] == nums[i-1])
            return true;

    return false;
}
