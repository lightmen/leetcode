char* getPermutation(int n, int k) {
    char *ret;
    int i,j;
    int A,num,len;
    int arr[10];
    int val;

    ret = (char *)malloc(sizeof(char) * (n+1));
    memset(ret,0,sizeof(char) * (n+1));
    memset(arr,0,sizeof(int) * 10);

    len = 0;
    for(i = n; i >= 1; --i){
        A = 1;
        for(j = i-1; j > 1; --j)
            A *= j;

        val = (k - 1) / A + 1;
        k  = (k - 1) % A + 1;

        num = 0;
        for(j = 1; j <= n; ++j){
            if(arr[j] == 0){
                num++;
            }
            if(num == val)
                break;
        }
        arr[j] = 1;
        ret[len] = j + '0';
        len++;
    }

    return ret;
}
