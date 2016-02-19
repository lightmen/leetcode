int maxProfit(int* prices, int pricesSize) {
    int i;
    int min,max;
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
    for(i = pricesSize - 2; i >= 0; --i){
        max = prices[i] > max ? prices[i] : max;
        right[i] = (max - prices[i]) > right[i+1] ? (max - prices[i]) : right[i+1];
    }


    max = 0;
    for(i = 0; i < pricesSize; ++i)
        max = (left[i] + right[i]) > max ? (left[i] + right[i]) : max;

    free(left);
    free(right);
    return max;
}
