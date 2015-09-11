int countPrimes(int n) {
    int ret = 0;
    int i,j;
    int *prime;
    prime = (int *)malloc(sizeof(int) * n);
    memset(prime,0,sizeof(int) * n);

    for(i = 2; i < n; ++i){
        if(prime[i])
            continue;
        ret++;
        for(j = 2*i; j < n; j += i)
            prime[j] = 1;
    }

    free(prime);
    return ret;
}
