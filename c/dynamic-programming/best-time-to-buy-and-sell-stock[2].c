int maxProfit(int* prices, int pricesSize) {
    int i;
    int ret,min;

    min = INT_MAX;
    ret = 0;
    for(i = 0; i < pricesSize; ++i){
        min = prices[i] < min ? prices[i] : min;
        ret = (prices[i] - min) > ret ? (prices[i] - min) : ret;
    }

    return ret;
}
