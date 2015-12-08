bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int start,end,mid;
    int row,col;

    start = 0;
    end = matrixRowSize * matrixColSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        row = mid / matrixColSize;
        col = mid % matrixColSize;
        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}
