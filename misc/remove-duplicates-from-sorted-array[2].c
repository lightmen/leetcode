int removeDuplicates(int A[], int n) {
    int ret = 1;
    int i;
    for(i = 1; i < n; ++i){
        if(A[i] != A[i-1])
            A[ret++] = A[i];
    }
    return n ? ret : 0;
}
