int maxProfit(int* prices, int pricesSize) {
    int min = INT_MAX;
    int i;
    int ret = 0;

    for(i = 0; i < pricesSize; ++i){
        min = prices[i] < min ? prices[i] : min;
        ret = prices[i] - min > ret ? prices[i] - min : ret;
    }

    return ret;
}
