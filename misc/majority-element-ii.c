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
    int i,count;

    ret = (int *)malloc(sizeof(int) * (less + 2));
    qsort(nums,numsSize,sizeof(int),cmp);

    cur = 0;
    i = 0;
    count = 0;
    while(i+count < numsSize){
        while(i + count < numsSize && nums[i+count] == nums[i]){
            count++;
        }
        if(count > less)
            ret[cur++] = nums[i];
        i += count;
        count = 0;
    }

    *returnSize = cur;
    return ret;
}
