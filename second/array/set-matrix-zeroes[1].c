void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int row0 = 0;
    int col0 = 0;
    int i,j;

    for(i = 0; i < matrixRowSize; ++i){
        if(matrix[i][0] == 0){
            col0 = 1;
            break;
        }
    }

    for(j = 0; j < matrixColSize; ++j){
        if(matrix[0][j] == 0){
            row0 = 1;
            break;
        }
    }

    for(i = 1; i < matrixRowSize; ++i){
        for(j = 1; j < matrixColSize; ++j){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(i = 1; i < matrixRowSize; ++i){
        for(j = 1; j < matrixColSize; ++j){
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    if(row0){
        for(j = 0; j < matrixColSize; ++j)
            matrix[0][j] = 0;
    }

    if(col0){
        for(i = 0; i < matrixRowSize; ++i){
            matrix[i][0] = 0;
        }
    }
}
