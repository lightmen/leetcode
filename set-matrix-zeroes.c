void setZeroes(int** matrix, int m, int n) {
    int *row,*col;
    int i,j;
    row = (int *)malloc(sizeof(int) * m);
    col = (int *)malloc(sizeof(int) * n);
    
    memset(row,0,sizeof(int) * m);
    memset(col,0,sizeof(int) * n);
    for(i = 0; i < m; ++i){
        for(j = 0; j < n; ++j){
            if(!matrix[i][j]){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    
    for(i = 0; i < m; ++i)
        for(j = 0; j < n; ++j){
            if(row[i])
                matrix[i][j] = 0;
            if(col[j])
                matrix[i][j] = 0;
        }
    
}
