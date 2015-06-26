/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int count;
int gk;

void helper(int **ret,int *arr, int k, int n, int index)
{
    int i;
    if(k == 0 && n == 0){
        int *tmp = (int *)malloc(sizeof(int) * gk);
        memcpy(tmp,arr,sizeof(int) * gk);
        ret[count] = tmp;
        count++;
        return ;
    }

    if(index > 9 || k <= 0 || n <= 0)
        return ;

    for(i = index; i <= 9; ++i){
        arr[gk-k] = i;
        helper(ret, arr,k-1,n-i,i+1);
    }
}
int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
    int **ret;
    int *arr;
    int i,len;
    len = 200;

    *columnSizes = (int *)malloc(sizeof(int) * len);
    ret = (int **)malloc(sizeof(int*) * len);
    arr = (int *)malloc(sizeof(int) * k);
    count = 0;
    gk = k;

    helper(ret,arr,k,n,1);
    *returnSize = count;
    for(i = 0; i < count; ++i)
        (*columnSizes)[i] = k;
    free(arr);

    return ret;
}
