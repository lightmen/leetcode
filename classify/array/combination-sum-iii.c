/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int top;
int count;
int alloc_size;
int *data;
int **ret;
int *col;

int *get_array(int *src, int len)
{
    int *dst = (int *)malloc(sizeof(int) * len);
    memcpy(dst,src,sizeof(int) * len);
    return dst;
}

void helper(int index, int k, int diff)
{
    if(top == k && diff == 0){
        col[count] = top;
        ret[count++] = get_array(data,top);
        if(count == alloc_size){
            alloc_size <<= 1;
            col = realloc(col,sizeof(int) * alloc_size);
            ret = realloc(ret,sizeof(int *) * alloc_size);
        }
        return ;
    }
    if(top == k || diff == 0)
        return ;

    int i;
    for(i = index; i <= 9; ++i){
        if(i > diff)
            break;
        data[top++] = i;
        helper(i+1,k,diff - i);
        top--;
    }
}

int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
    top = 0;
    count= 0;
    alloc_size = 500;

    ret = (int **)malloc(sizeof(int *) * alloc_size);
    col = (int *)malloc(sizeof(int *) * alloc_size);
    data = (int *)malloc(sizeof(int *) * 9);

    helper(1,k,n);

    *columnSizes = col;
    *returnSize = count;
    return ret;
}
