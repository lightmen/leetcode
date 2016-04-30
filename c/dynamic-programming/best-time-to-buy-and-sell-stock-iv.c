int max_2(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int k, int* prices, int pricesSize) {
    int *local,*global;
    int ret = 0;
    int i,j;

    if(k >= pricesSize){
        for(i = 1; i < pricesSize; ++i)
            if(prices[i] - prices[i-1] > 0)
                ret += prices[i] - prices[i-1];
        return ret;
    }

    local = (int *)malloc(sizeof(int) * (k + 1));
    global= (int *)malloc(sizeof(int) * (k + 1));

    memset(local,0,sizeof(int) * (k + 1));
    memset(global,0,sizeof(int) * (k + 1));

    for(i = 0; i < pricesSize - 1; ++i){
        ret = prices[i+1] - prices[i];

        for(j = k; j >= 1; --j){
            local[j] = max_2(global[j-1] + max_2(ret,0), local[j]+ret);
            global[j] = max_2(global[j],local[j]);
        }
    }

    ret = global[k];
    free(local);
    free(global);
    return ret;
}
