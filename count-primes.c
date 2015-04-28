int countPrimes(int n) {
    int *prime;
    int count = 0;
    prime = (int *)malloc(sizeof(int) * n);
    memset(prime,0,sizeof(int) * n);
    int i,j;
    for(i = 2; i < n; ++i){
        if(!prime[i]){
            count++;
            j = 2;
            while(j * i < n){
                prime[j*i] = 1;
                j++;
            }
        }
    }
    return count;
}
