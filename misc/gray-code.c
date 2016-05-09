/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void rec(int *ret, int n, int *count)
{
    if(n == 0){
        ret[*count] = 0;
        (*count)++;
        return ;
    }

    int i,j;
    int add = 1 << (n-1);

    rec(ret,n-1,count);

    j = *count;
    for(i = *count-1; i >= 0; --i)
        ret[j++] = ret[i] + add;

    (*count) = j;
}

int* grayCode(int n, int* returnSize) {
    int len = 1 << n;
    int *ret;

    ret = (int *)malloc(sizeof(int) * len);

    (*returnSize) = 0;
    rec(ret,n,returnSize);

    return ret;
}
