int maxProfit(int* prices, int pricesSize) {
    int i;
    int *min,*max;
    int ret;

    min = (int *)malloc(sizeof(int) * pricesSize);
    max = (int *)malloc(sizeof(int) * pricesSize);

    min[0] = prices[0];
    for(i = 1; i < pricesSize; ++i){
        min[i] = prices[i] < min[i-1] ? prices[i] : min[i-1];
    }

    max[pricesSize-1] = prices[pricesSize-1];
    for(i = pricesSize - 2; i >= 0; --i)
        max[i] = prices[i] > max[i+1] ? prices[i] : max[i+1];

    ret = 0;
    for(i = 0; i < pricesSize; ++i)
        if(max[i] - min[i] > ret)
            ret = max[i] - min[i];

    free(min);
    free(max);
    return ret;
}
