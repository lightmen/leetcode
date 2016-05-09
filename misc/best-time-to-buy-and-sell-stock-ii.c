int maxProfit(int* prices, int pricesSize) {
    int i;
    int ret = 0;

    for(i = 1; i < pricesSize; ++i){
        if(prices[i] > prices[i-1])
            ret += prices[i] - prices[i-1];
    }

    return ret;
}
