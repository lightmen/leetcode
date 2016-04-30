static int leq_count(int *nums, int numsSize, int target)
{
    int i,ret;

    ret = 0;
    for(i = 0;i < numsSize; ++i)
        if(nums[i] <= target)
            ++ret;

    return ret;
}

int findDuplicate(int* nums, int numsSize) {
    int start,end,mid,c;
    start = 1;
    end = numsSize-1;

    while(start <= end){
        mid = (start + end) / 2;
        c= leq_count(nums,numsSize,mid);
        if(c <= mid)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return start;
}
