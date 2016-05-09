static inline int max(int a,int b)
{
    return a > b ? a : b;
}
static inline int min(int a, int b)
{
    return a < b ? a : b;    
}
int calculateMinimumHP(int **dungeon, int m, int n) {
    int **dp;
    int i,j;
    dp = (int **)malloc(sizeof(int *) * m);
    for(i = 0; i < m; ++i)
        dp[i] = (int *)malloc(sizeof(int) * n);
        
    dp[m-1][n-1] = max(-dungeon[m-1][n-1],0);
    
    for(i = m - 2; i >= 0; --i)
        dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1],0);
    for(j = n - 2; j >= 0; --j)
        dp[m-1][j] = max(dp[m-1][j+1] - dungeon[m-1][j],0);
        
    for(i = m-2; i >= 0; --i){
        for(j = n-2; j >= 0; --j){
            dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j],0);
        }
    }
    
    return dp[0][0] + 1;
}
