int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    int i;

    for(i = 1; i < pricesSize; ++i)
        if(prices[i] > prices[i-1])
            ret += prices[i] - prices[i-1];

    return ret;
}
