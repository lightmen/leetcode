/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int *ret;
    int less = numsSize / 3;
    int cur;
    int begin,end;

    ret = (int *)malloc(sizeof(int) * (less + 2));
    qsort(nums,numsSize,sizeof(int),cmp);

    cur = 0;
    begin = end = 0;
    while(end < numsSize){
        ++end;
        if((end == numsSize || nums[end] != nums[begin])
            && end - begin > less){
            ret[cur++] = nums[begin];
            begin = end;
        }else if(end < numsSize && nums[end] != nums[begin]){
            begin = end;
        }
    }

    *returnSize = cur;
    return ret;
}
