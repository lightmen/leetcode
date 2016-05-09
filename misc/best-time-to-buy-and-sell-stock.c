int maxProfit(int prices[], int n){
    int i,min,profit;
    min = prices[0];
    profit = 0;
    for(i = 0; i < n; ++i){
        if(prices[i] - min > profit)
            profit = prices[i] - min;
        if(prices[i] < min)
            min = prices[i];
    }
    return profit;
}
