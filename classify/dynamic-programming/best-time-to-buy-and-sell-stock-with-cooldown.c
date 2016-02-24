/*
 * buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
 * sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。
 * rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。
 * buy[i] = max(rest[i-1] - price, buy[i-1]);
 * sell[i] = max(buy[i-1] + price, sell[i-1]);
 * rest[i] = max(buy[i-1], sell[i-1], rest[i-1]);
 * 注意：
 * rest[i] = max(sell[i-1], rest[i-1])，这保证了[buy, rest, buy]不会出现。
 *
 * 由于冷冻期的存在，可知rest[i] = sell[i-1]，可以将上面三个递推式精简到两个：
 * buy[i] = max(sell[i-2] - price, buy[i-1]);
 * sell[i] = max(buy[i-1] + price, sell[i-1]);
*/

int max_2(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int i;
    int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;

    for(i = 0; i < pricesSize; ++i){
        pre_buy = buy;
        buy = max_2(pre_sell - prices[i],pre_buy);
        pre_sell = sell;
        sell = max_2(pre_buy + prices[i], pre_sell);
    }

    return sell;
}
