int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int perimeter = 0;
    int i,j;

    for(i = 0; i < gridRowSize; ++i){
        for(j = 0; j < gridColSize; ++j){
            if(grid[i][j] == 0)
                continue;

            if(j == 0 || grid[i][j-1] == 0)
                perimeter++;
            if(i == 0 || grid[i-1][j] == 0)
                perimeter++;
            if(j == gridColSize -1 || grid[i][j+1] == 0)
                perimeter++;
            if(i == gridRowSize -1 || grid[i+1][j] == 0)
                perimeter++;
        }
    }

    return perimeter;
}
