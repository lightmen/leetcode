int maxProfit(int* prices, int pricesSize) {
    int *left,*right;
    int min,max;
    int diff;
    int i;
    int ret = 0;

    left = (int *)malloc(sizeof(int) * pricesSize);
    right = (int *)malloc(sizeof(int) * pricesSize);

    min = prices[0];
    left[0] = 0;
    for(i = 1; i < pricesSize; ++i){
        min = prices[i] < min ? prices[i] : min;
        diff = prices[i] - min;
        left[i] = diff > left[i-1] ? diff : left[i-1];
    }

    max = prices[pricesSize-1];
    right[pricesSize-1] = 0;
    for(i = pricesSize-2; i >= 0; --i){
        max = prices[i] > max ? prices[i] : max;
        diff = max - prices[i];
        right[i] = diff > right[i+1] ? diff : right[i+1];
    }

    for(i = 0; i < pricesSize; ++i){
        if(left[i] + right[i] > ret)
            ret = left[i] + right[i];
    }

    free(left);
    free(right);
    return ret;
}
