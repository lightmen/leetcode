int maxProfit(int* prices, int pricesSize) {
    int i;
    int min,max,ret;
    int *left,*right;
    left = (int *)malloc(sizeof(int) * pricesSize);
    right = (int *)malloc(sizeof(int) * pricesSize);

    min = prices[0];
    left[0] = 0;
    for(i = 1; i < pricesSize; ++i){
        min = prices[i] < min ? prices[i] : min;
        left[i] = (prices[i] - min) > left[i-1] ? (prices[i] - min) : left[i-1];
    }

    max = prices[pricesSize - 1];
    right[pricesSize - 1] = 0;
    ret = 0;
    for(i = pricesSize - 2; i >= 0; --i){
        max = prices[i] > max ? prices[i] : max;
        right[i] = (max - prices[i]) > right[i+1] ? (max - prices[i]) : right[i+1];
        ret = (left[i] + right[i]) > ret ? (left[i] + right[i]) : ret;
    }

    free(left);
    free(right);
    return ret;
}
