static int max(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int k, int* prices, int pricesSize) {
    int ret = 0;
    int i,j;
    int *local,*global;
    int tmp;

    if(k >= pricesSize){
        for(i = 1; i < pricesSize; ++i){
            if(prices[i] - prices[i-1] > 0)
                ret += prices[i] - prices[i-1];
        }
        return ret;
    }

    local = (int *)malloc(sizeof(int) * (k + 1));
    global = (int *)malloc(sizeof(int) * (k + 1));

    memset(local,0,sizeof(int) * (k + 1));
    memset(global,0,sizeof(int) * (k + 1));

    for(i = 0; i < pricesSize - 1; ++i){
        tmp = prices[i+1] - prices[i];

        for(j = k; j >= 1; --j){
            local[j] = max(global[j-1] + max(tmp,0),local[j] + tmp);
            global[j] = max(local[j],global[j]);
        }
    }

    ret = global[k];
    free(local);
    free(global);

    return ret;
}
