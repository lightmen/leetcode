/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int **ret;
    int *col;
    int count = 1 << numsSize;
    int i,j;
    int bit;

    ret = (int **)malloc(sizeof(int *) * count);
    col = (int *)malloc(sizeof(int) * count);

    qsort(nums,numsSize,sizeof(int),cmp);

    for(i = 0; i < count; ++i){
        col[i] = 0;
        ret[i] = (int *)malloc(sizeof(int *) * numsSize);
        bit = i;
        j = 0;
        while(bit > 0){
            if(bit & 1)
                ret[i][col[i]++] = nums[j];
            j++;
            bit >>= 1;
        }
    }

    *returnSize = count;
    *columnSizes = col;
    return ret;
}
