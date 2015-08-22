/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int idx;
int **ret;
int *col;
int size;

void helper(int *arr, int len, int *nums,int pos)
{
    int i;
    ret[idx] = (int *)malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i)
        ret[idx][i] = arr[i];
    col[idx] = len;
    idx++;

    for(i = pos; i < size; ++i){
        arr[len] = nums[i];
        helper(arr,len+1,nums,i+1);
    }
}

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int *arr;
    int count = 1 << numsSize;
    size = numsSize;
    idx = 0;

    ret = (int **)malloc(sizeof(int *) * count);
    col = (int *)malloc(sizeof(int) * count);
    arr = (int *)malloc(sizeof(int) * numsSize);

    qsort(nums,numsSize,sizeof(int),cmp);

    helper(arr,0,nums,0);

    *returnSize = count;
    *columnSizes = col;
    free(arr);
    return ret;
}
