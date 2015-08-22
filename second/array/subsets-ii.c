/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **ret;
int *col;
int size;
int alloc_size;
int idx;

void helper(int *arr, int len, int *nums, int pos)
{
    int i;

    ret[idx] = (int *)malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i){
        ret[idx][i] = arr[i];
    }
    col[idx] = len;
    idx++;

    for(i = pos; i < size; ++i){
        if(i > pos && nums[i-1] == nums[i])
            continue;
        arr[len] = nums[i];
        helper(arr,len+1,nums,i+1);
    }
}

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int *arr;
    size = numsSize;
    alloc_size = 1 << numsSize;
    idx = 0;

    ret = (int **)malloc(sizeof(int *) * alloc_size);
    col = (int *)malloc(sizeof(int) * alloc_size);
    arr = (int *)malloc(sizeof(int) * numsSize);

    qsort(nums,numsSize,sizeof(int), cmp);

    helper(arr,0,nums,0);

    free(arr);
    *columnSizes = col;
    *returnSize = idx;
    return ret;
}
