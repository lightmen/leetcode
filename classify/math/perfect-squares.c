void get_square(int *arr, int k)
{
    int i;
    int min;
    int x;

    if(arr[k])
        return ;

    min = k;
    for(i = 1; i*i < k; ++i){
        x = i * i;
        if(arr[k-x] == 0)
            get_square(arr,k-x);
        min = 1 + arr[k-x] < min ? 1 + arr[k-x] : min;
    }

    arr[k] = min;
}

int numSquares(int n) {
    int *arr;
    int i,ret;

    arr = (int *)malloc(sizeof(int) * (n+1));
    memset(arr,0,sizeof(int) * (n+1));
    for(i = 1; i * i <= n; ++i)
        arr[i*i] = 1;

    get_square(arr, n);
    ret = arr[n];

    free(arr);
    return ret;
}
