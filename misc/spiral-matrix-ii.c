/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int num) {
    int **ret;
    int i,count,row,col,m,n;

    ret = (int **)malloc(sizeof(int *) * num);
    for(i = 0; i < num; ++i)
        ret[i] = (int *)malloc(sizeof(int) * num);
    
    count = 1;
    row = num;
    col = num;
    m = 0;
    n = -1;
    while(1){
        for(i = 0; i < col; ++i)
            ret[m][++n] = count++;
        if(--row <= 0)
            break;
        for(i = 0; i < row; ++i)
            ret[++m][n] = count++;
        if(--col <= 0)
            break;
        for(i = 0; i < col; ++i)
            ret[m][--n] = count++;
        if(--row <= 0)
            break;
        for(i = 0; i < row; ++i)
            ret[--m][n] = count++;
        if(--col <= 0)
            break;
    }

    return ret;
}
