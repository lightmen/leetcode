/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recursion(int **ret,int *flag,int *arr,int *nums,
                int numsSize,int *index,int count)
{
    int i;
    if(count == numsSize){
        for(i = 0; i < numsSize; ++i)
            ret[*index][i] = arr[i];
        (*index)++;
    }else{
        for(i = 0; i < numsSize; ++i){
            if(!flag[i]){
                arr[count] = nums[i];
                flag[i] = 1;
                recursion(ret,flag,arr,nums,numsSize,index,count+1);
                flag[i] = 0;
            }
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int **ret;
    int i,len;
    int *flag;
    int *arr;

    len = 1;
    for(i = 2; i <= numsSize; ++i)
        len *= i;

    ret = (int **)malloc(sizeof(int *) * len);
    for(i = 0; i < len; ++i)
        ret[i] = (int *)malloc(sizeof(int) * numsSize);

    flag = (int *)malloc(sizeof(int) * numsSize);
    memset(flag,0,sizeof(int) * numsSize);

    arr = (int *)malloc(sizeof(int) * numsSize);

    recursion(ret,flag,arr,nums,numsSize,returnSize,0);

    free(flag);
    free(arr);
    return ret;
}
