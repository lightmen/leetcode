/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int size = matrixRowSize * matrixColSize;
    int i,count;
    int *ret;
    int left,right,up,down;

    ret = (int *)malloc(sizeof(int) * size);
    count = 0;

    left = 0;
    up = 0;
    right = matrixColSize - 1;
    down = matrixRowSize - 1;

    while(left <= right && up <= down){
        for(i = left; i <= right; ++i)
            ret[count++] = matrix[up][i];
        if(count == size)
            break;
        for(i = up + 1; i <= down; ++i)
            ret[count++] = matrix[i][right];
        if(count == size)
            break;
        for(i = right - 1; i >= left; --i)
            ret[count++] = matrix[down][i];
        if(count == size)
            break;
        for(i = down - 1; i > up; --i)
            ret[count++] = matrix[i][left];
        if(count == size)
            break;
        left++;
        up++;
        right--;
        down--;
    }

    return ret;
}
