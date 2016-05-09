/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
static int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int **ret,*col;
    int *tmp;
    int count = 1 << numsSize;
    int i,j,value,k;
    ret = (int **)malloc(sizeof(int *) * count);
    tmp = (int *) malloc(sizeof(int) * numsSize);
    col = (int *)malloc(sizeof(int) * count);

    qsort(nums,numsSize,sizeof(int),cmp);
    for(i = 0; i < count; ++i){
        j = 0;
        value = i;
        k = 0;
        while(value){
            if(value & 0x1){
                tmp[k++] = nums[j];
            }
            value >>= 1;
            j++;
        }
        ret[i] = (int *)malloc(sizeof(int) * k);
        for(j = 0; j < k; ++j){
            ret[i][j] = tmp[j];
        }
        col[i] = k;
    }
    free(tmp);
    
    *returnSize = count;
    *columnSizes = col;
    return ret;
}
