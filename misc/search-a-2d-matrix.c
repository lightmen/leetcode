bool searchMatrix(int **matrix, int m, int n, int target) {
    int mid,begin,end,tmp;
    begin = 0;
    end = m * n - 1;
    while(begin <= end){
        mid = (begin + end) / 2;
        tmp = matrix[mid/n][mid%n];
        if(tmp == target)
            return true;
        else if(tmp > target)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return false;
}
