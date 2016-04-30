#define min_2(x,y) ({ \
    int _x = (x); \
    int _y = (y); \
    _x < _y ? _x : _y; \
})

#define MAX_VALUE (INT_MAX - 1)

int coinChange(int* coins, int coinsSize, int amount) {
    int *dp;
    int i,j;
    int ret;

    dp = (int *)malloc(sizeof(int) * (amount+1));

    dp[0] = 0;
    for(i = 1; i <= amount; ++i)
        dp[i] = MAX_VALUE;

    for(i = 0; i <=amount; ++i){
        for(j = 0; j < coinsSize; j++)
            if(i + coins[j] <= amount)
                dp[i+coins[j]] = min_2(dp[i+coins[j]], dp[i] + 1);
    }

    ret = dp[amount];
    free(dp);

    return ret == MAX_VALUE ? -1 : ret;
}
