/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ret;
    int *front;
    int *back;
    int i;
    front = (int *)malloc(sizeof(int) * numsSize);
    back = (int *)malloc(sizeof(int) * numsSize);
    ret = (int *)malloc(sizeof(int) * numsSize);

    front[0] = 1;
    for(i = 1; i < numsSize; ++i)
        front[i] = front[i-1]*nums[i-1];

    back[numsSize-1] = 1;
    for(i = numsSize-2; i >= 0; --i)
        back[i] = back[i+1] * nums[i+1];

    for(i = 0; i < numsSize; ++i)
        ret[i] = front[i] * back[i];

    *returnSize = numsSize;

    free(front);
    free(back);

    return ret;
}
