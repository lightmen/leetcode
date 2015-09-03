int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    int *left;
    int *right;
    int i;
    left = (int *)malloc(sizeof(int) * pricesSize);
    right = (int *)malloc(sizeof(int) * pricesSize);

    left[0] = prices[0];
    for(i = 1; i < pricesSize; ++i)
        left[i] = prices[i] < left[i-1] ? prices[i] : left[i-1];

    right[pricesSize-1] = prices[pricesSize-1];
    for(i = pricesSize-2; i >= 0; --i)
        right[i] = prices[i] > right[i+1] ? prices[i] : right[i+1];

    for(i = 0; i < pricesSize-1; ++i)
        ret = right[i+1] - left[i] > ret ? right[i+1] - left[i] : ret;

    free(left);
    free(right);
    return ret;
}
