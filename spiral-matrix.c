/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int row, int col) {
    int *ret;
    int i,count;
    int m,n;
    ret = (int *)malloc(sizeof(int) * (row * col));
    
    count = 0;
    m = 0;
    n = -1;
    while(1){
        for(i = 0; i < col; ++i)
            ret[count++] = matrix[m][++n];
        if(--row <= 0)
            break;
        for(i = 0; i < row; ++i)
            ret[count++] = matrix[++m][n];
        if(--col <= 0)
            break;
        for(i = 0; i < col; ++i)
            ret[count++] = matrix[m][--n];
        if(--row <= 0)
            break;
        for(i = 0; i < row; ++i)
            ret[count++] = matrix[--m][n];
        if(--col <= 0)
            break;
    }
    
    return ret;
}
