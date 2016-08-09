int countPrimes(int n) {
    int *arr;
    int count = 0;
    int i,j;

    arr = malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);
    for(i = 2; i < n; ++i){
        if(arr[i])
            continue;
        ++count;
        for(j = i * 2; j < n; j += i)
            arr[j] = 1;
    }

    free(arr);
    return count;
}
