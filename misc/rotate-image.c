static void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j;
    int start,end;
    for(j = 0; j < matrixColSize; ++j)
    {
        start = 0;
        end = matrixRowSize - 1;
        while(start < end){
            swap(&matrix[start][j],&matrix[end][j]);
            ++start;
            --end;
        }
    }
    
    for(i = 0; i < matrixRowSize; ++i)
        for(j = i + 1; j < matrixColSize; ++j){
            swap(&matrix[i][j],&matrix[j][i]);
        }
}
