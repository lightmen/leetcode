bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int start,end,mid;
    int tmp;

    start = 0;
    end = matrixRowSize * matrixColSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        tmp= matrix[mid / matrixColSize][mid % matrixColSize];
        if(tmp == target)
            return true;
        else if(tmp > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}
