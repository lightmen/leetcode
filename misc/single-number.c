int singleNumber(int A[], int n) {
    int ret,i;
    ret = 0;
    for(i = 0; i < n; ++i)
        ret ^= A[i];
    return ret;
}
