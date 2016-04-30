int maxCoins(int* nums, int numsSize) {
    int *arr;
    int **dp;
    int i,j,k,step;
    int tmp;

    arr = malloc(sizeof(int) * (numsSize + 2));
    dp = malloc(sizeof(int *) * (numsSize + 2));
    for(i = 0; i < numsSize + 2; ++i){
        dp[i] = malloc(sizeof(int) * (numsSize + 2));
        memset(dp[i], 0, sizeof(int) * (numsSize + 2));
    }

    arr[0] = arr[numsSize + 1] = 1;
    for(i = 1; i <= numsSize; ++i)
        arr[i] = nums[i-1];

    for(step = 1; step <= numsSize; ++step){
        for(i = 1; i <= numsSize - step + 1; ++i){
            j = i + step - 1;
            for(k = i; k <= j; ++k){
                tmp = dp[i][k-1] + arr[i-1] * arr[k] * arr[j+1] + dp[k+1][j];
                if(tmp > dp[i][j])
                    dp[i][j] = tmp;
            }
        }
    }

    tmp = dp[1][numsSize];
    free(arr);
    for(i = 0; i < numsSize + 2; ++i)
        free(dp[i]);
    free(dp);

    return tmp;
}
