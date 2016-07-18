int numTrees(int n) {
    int *num;
    int ret;

    if(n == 1)
        return 1;

    num = malloc(sizeof(int) * (n + 1));
    memset(num, 0, sizeof(int) * (n + 1));
    num[1] = 1;
    num[0] = 1;
    for(int i = 2;i <= n; ++i){
        for(int j = 0; j < i; ++j)
            num[i] +=(num[j] * num[i - j - 1]);
    }

    ret = num[n];
    free(num);
    return ret;
}
