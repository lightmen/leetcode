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
        for(j = 0; j < matrixColSize; ++j){
            if(row[i] || col[j])
                matrix[i][j] = 0;
        }
    }

    free(row);
    free(col);
}
