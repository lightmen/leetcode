bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row,col;

    row = matrixRowSize - 1;
    col = 0;

    while(row >= 0 && col < matrixColSize){
        if(matrix[row][col] == target)
            return true;
        if(matrix[row][col] > target)
            --row;
        else
            ++col;
    }

    return false;
}
