static int cmp(const int *a, const int *b)
{
    return *(int *)b - *(int *)a;
}
int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmp);
    return nums[k-1];
}
