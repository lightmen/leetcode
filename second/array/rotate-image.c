void reverse(int *nums, int start, int end)
{
    int tmp;
    while(start < end){
        tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start++;
        end--;
    }
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j;
    int tmp;

    for(i = 0; i < matrixRowSize; ++i){
        for(j = 0; j < i; ++j){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for(i = 0; i < matrixRowSize; ++i){
        reverse(matrix[i],0,matrixColSize-1);
    }
}
