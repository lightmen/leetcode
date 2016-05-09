int minPathSum(int **grid, int nRows, int nCols) {
    int dp[nRows][nCols];
    int i,j;
        
    for(i = 0; i < nRows; ++i){
        for(j = 0; j < nCols; ++j){
            dp[i][j] = grid[i][j];
            if(i == 0 && j == 0)
                continue;
            else if(j == 0)
                dp[i][j] += dp[i-1][j];
            else if(i == 0)
                dp[i][j] += dp[i][j-1];
            else
                dp[i][j] += (dp[i-1][j] > dp[i][j-1]) ?
                            dp[i][j-1] : dp[i-1][j];
        }
    }
    
    return dp[nRows-1][nCols-1];
}
