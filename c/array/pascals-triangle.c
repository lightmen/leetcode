/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    int **ret;
    int i,j;
    int *col;

    col = (int *)malloc(sizeof(int) * numRows);
    ret = (int **)malloc(sizeof(int *) * numRows);
    for(i = 0; i < numRows; ++i){
        col[i] = i + 1;
        ret[i] = (int *)malloc(sizeof(int) * col[i]);

        ret[i][0] = 1;
        for(j = 1; j < col[i] - 1; ++j)
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        ret[i][col[i]-1] = 1;
    }

    *returnSize = numRows;
    *columnSizes = col;
    return ret;
}
