int candy(int* ratings, int ratingsSize) {
    int *count;
    int i,j;
    int ret = ratingsSize;
    int k = 1;

    count = (int *)malloc(sizeof(int)*ratingsSize);
    count[0] = 0;
    for(i = 1; i < ratingsSize; ++i){
        count[i] = 0;
        if(ratings[i] > ratings[i-1]){
            count[i] = count[i-1] + 1;
        }
    }
    
    for(i = ratingsSize - 2; i >= 0; --i){
        if(ratings[i] > ratings[i+1]){
            count[i] = count[i] > k ? count[i] : k;
            k++;
        }else{
            k = 1;
        }
    }
    
    for(i = 0; i < ratingsSize; ++i)
        ret += count[i];
    
    return ret;
}
