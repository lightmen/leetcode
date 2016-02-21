int max_2(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int k, int* prices, int pricesSize) {
    int **local,**global;
    int i,j;
    int value;

    value = 0;
    if(k >= pricesSize){
        for(i = 0; i < pricesSize-1; ++i)
            if(prices[i+1] - prices[i] > 0)
                value += (prices[i+1] - prices[i]);
        return value;
    }

    local = (int **)malloc(sizeof(int *) * pricesSize);
    global = (int **)malloc(sizeof(int *) * pricesSize);
    for(i = 0; i < pricesSize; ++i){
        local[i] = (int *)malloc(sizeof(int) * (k + 1));
        global[i] = (int *)malloc(sizeof(int) * (k + 1));

        memset(local[i],0,sizeof(int) * (k + 1));
        memset(global[i],0,sizeof(int) * (k + 1));
    }

    for(i = 1; i < pricesSize; ++i){
        value = prices[i] - prices[i-1];

        for(j = 1; j <= k; ++j){
            local[i][j] = max_2(global[i-1][j-1] + max_2(value,0), local[i-1][j] + value);
            global[i][j] = max_2(global[i-1][j], local[i][j]);
        }
    }

    value = global[pricesSize-1][k];
    for(i = 0; i < pricesSize; ++i){
        free(local[i]);
        free(global[i]);
    }

    free(local);
    free(global);
    return value;
}
