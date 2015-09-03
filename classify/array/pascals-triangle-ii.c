/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int *ret;
    int i,j;
    int tmp,prev;

    ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    memset(ret,0,sizeof(int) * (rowIndex + 1));

    for(i = 0; i <= rowIndex; ++i){
        ret[0] = 1;
        prev = ret[0];
        for(j = 1; j < i; ++j){
            tmp = ret[j];
            ret[j] = prev + ret[j];
            prev = tmp;
        }
        ret[i] = 1;
    }

    *returnSize = rowIndex + 1;
    return ret;
}
