struct NumMatrix {
    int row;
    int col;
    int **arr;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    struct NumMatrix *nm;
    int i,j;
    nm = malloc(sizeof(struct NumMatrix));
    nm->row = matrixRowSize + 1;
    nm->col = matrixColSize + 1;
    nm->arr = malloc(sizeof(int *) * nm->row);
    for(i = 0; i < nm->row; ++i){
        nm->arr[i] = malloc(sizeof(int) * nm->col);
        nm->arr[i][0] = 0;
    }

    memset(nm->arr[0], 0, sizeof(int) * nm->col);

    for(i = 1; i < nm->row; ++i){
        for(j = 1; j < nm->col; ++j){
            nm->arr[i][j] = matrix[i-1][j-1] + nm->arr[i][j-1] +
                nm->arr[i-1][j] - nm->arr[i-1][j-1];
        }
    }

    return nm;
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {
    int **arr = numMatrix->arr;

    return arr[row2+1][col2+1] - arr[row1][col2+1] - arr[row2+1][col1] + arr[row1][col1];
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) {
    int i,j;
    for(i = 0; i < numMatrix->row; ++i)
        free(numMatrix->arr[i]);
    free(numMatrix->arr);
    free(numMatrix);
}

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);
