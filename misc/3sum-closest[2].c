static int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int i,start,end;
    int sum,ret = nums[0]+nums[1] + nums[2];
    qsort(nums,numsSize,sizeof(int),cmp);
    
    for(i = 0; i < numsSize - 2; ++i){
        start = i + 1;
        end = numsSize - 1;
        while(start < end){
            sum = nums[i] + nums[start] + nums[end];
            if(abs(sum - target) < abs(ret - target))
                ret = sum;
            if(ret == target)
                return ret;
            if(sum  > target)
                --end;
            else
                ++start;
        }
    }
    
    return ret;
}
