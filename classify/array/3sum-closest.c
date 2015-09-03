static int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i,start,end;
    int ret = nums[0] + nums[1] + nums[2];
    int sum;

    qsort(nums,numsSize,sizeof(int),cmp);
    for(i = 0; i < numsSize - 2; ++i){
        start = i + 1;
        end = numsSize - 1;
        while(start < end){
            sum = nums[i] + nums[start] + nums[end];
            if(abs(ret - target) > abs(sum - target))
                ret = sum;
            if(sum > target)
                --end;
            else
                ++start;
        }
    }

    return ret;
}
