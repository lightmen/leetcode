int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int **arr;
    int ret;
    int i,j;

    arr = (int **)malloc(sizeof(int *) * gridRowSize);
    for(i = 0; i < gridRowSize; ++i)
        arr[i] = (int *)malloc(sizeof(int) * gridColSize);

    for(i = 0; i < gridRowSize; ++i){
        for(j = 0; j < gridColSize; ++j){
            arr[i][j] = grid[i][j];
            if(i - 1 >= 0 && j - 1 < 0)
                arr[i][j] += arr[i-1][j];
            else if(j - 1 >= 0 && i - 1 < 0)
                arr[i][j] += arr[i][j-1];
            else if(i - 1 >= 0 && j - 1 >= 0)
                arr[i][j] += arr[i-1][j] < arr[i][j-1] ?
                        arr[i-1][j] : arr[i][j-1];
        }
    }

    ret = arr[gridRowSize-1][gridColSize-1];

    for(i = 0; i < gridRowSize; ++i)
        free(arr[i]);
    free(arr);

    return ret;
}
