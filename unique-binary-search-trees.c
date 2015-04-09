int numTrees(int n) {
    int *arr;
    int i,j;
    arr = (int *)malloc(sizeof(int) * (n + 1));
    memset(arr,0,sizeof(int) * (n+1));
    arr[0] = 1;
    
    for(i = 1; i <= n; ++i){
        for(j = 0; j < i; ++j)
            arr[i] += arr[j] * arr[i-j-1];
    }
    return arr[n];
}
