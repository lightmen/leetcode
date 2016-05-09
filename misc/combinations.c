/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int idx;

void rec(int **ret, int *rcd, int n, int k, int l, int p)
{
    int i;
    if(l == k){
        memcpy(ret[idx],rcd,sizeof(int)*k);
        idx++;
        return ;
    }

    for(i = p; i <= n; ++i){
        rcd[l] = i;
        rec(ret,rcd,n,k,l+1,i+1);
    }
}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
    long len = 1; //len must be long, or it will overflow if n is 13
    int **ret;
    int *rcd;
    int i;

    for(i = n; i > n - k; --i)
        len *= i;
    for(i = k; i >= 2; --i)
        len /= i;

    rcd = (int *)malloc(sizeof(int) * k);
    ret = (int **)malloc(sizeof(int *) * len);
    *columnSizes = (int *)malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i){
        ret[i] = (int *)malloc(sizeof(int) * k);
        (*columnSizes)[i] = k;
    }

    idx = 0;
    rec(ret,rcd,n,k,0,1);

    *returnSize = len;

    free(rcd);
    return ret;
}
