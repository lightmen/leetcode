/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **ret;
    int i;
    int left,right,up,down;
    int cur = 1;

    ret = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; ++i)
        ret[i] = (int *)malloc(sizeof(int) * n);

    left = 0;
    up = 0;
    down = n - 1;
    right = n - 1;

    while(left <= right && up <= down){
        for(i = left; i <= right; ++i)
            ret[up][i] = cur++;
        for(i = up + 1; i <= down; ++i)
            ret[i][right] = cur++;
        for(i = right - 1; i >= left; --i)
            ret[down][i] = cur++;
        for(i = down - 1; i > up; --i)
            ret[i][left] = cur++;
        left++;
        up++;
        down--;
        right--;
    }

    return ret;
}
