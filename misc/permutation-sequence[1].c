char* getPermutation(int n, int k) {
    char *ret;
    int arr[9];
    int A;
    int i,j;
    int len;
    int key;

    ret = (char *)malloc(sizeof(char) * (n+1));
    ret[n] = 0;

    A = 1;
    for(i = 1; i <= n; ++i){
        A *= i;
        arr[i-1] = i + '0';
    }

    k--;
    len = 0;
    for(i = n;i >= 1; --i){
        A /= i;
        key = k / A;
        k %= A;
        ret[len++] = arr[key];

        for(j = key; j < n-1; ++j)
            arr[j] = arr[j+1];
    }

    return ret;
}
