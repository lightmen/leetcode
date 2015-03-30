int singleNumber(int A[], int n) {
    int bits[32];
    int i,j;
    int ret = 0;
    memset(bits,0,sizeof(int) * 32);
    for(i = 0; i < n; ++i)
        for(j = 0; j < 32; ++j)
            bits[j] += ((A[i] >> j) & 0x1);
            
    for(j = 0; j < 32; ++j)
        if(bits[j] % 3)
            ret += (1 << j);
    return ret;
}
