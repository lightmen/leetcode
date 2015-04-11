void rec(char **grid,int row, int col,int i,int j)
{
    if(i >= row || i < 0)
        return ;
    if(j >= col || j < 0)
        return ;
    if(grid[i][j] != '1')
        return ;
    grid[i][j] = '0';
    rec(grid,row,col,i+1,j);
    rec(grid,row,col,i-1,j);
    rec(grid,row,col,i,j+1);
    rec(grid,row,col,i,j-1);
}
int numIslands(char **grid, int numRows, int numColumns) {
    int i,j;
    int ret = 0;
    
    for(i = 0; i < numRows; ++i){
        for(j = 0; j < numColumns; ++j){
            if(grid[i][j] == '0')
                continue;
            ret++;
            rec(grid,numRows,numColumns,i,j);
        }
    }
    
    return ret;
}
