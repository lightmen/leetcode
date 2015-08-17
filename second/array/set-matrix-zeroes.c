void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int *row;
    int *col;
    int i,j;

    row = (int *)malloc(sizeof(int) * matrixRowSize);
    col = (int *)malloc(sizeof(int) * matrixColSize);
    memset(row, 0, sizeof(int) * matrixRowSize);
    memset(col, 0, sizeof(int) * matrixColSize);

    for(i = 0; i < matrixRowSize; ++i){
        for(j = 0; j < matrixColSize; ++j){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(i = 0; i < matrixRowSize; ++i){
        if(row[i] == 0)
            continue;

        for(j = 0; j < matrixColSize; ++j){
            matrix[i][j] = 0;
        }
    }

    for(j = 0; j < matrixColSize; ++j){
        if(col[j] == 0)
            continue;

        for(i = 0; i < matrixRowSize; ++i){
            matrix[i][j] = 0;
        }
    }

    free(row);
    free(col);
}
