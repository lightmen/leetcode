int removeDuplicates(int A[], int n) {
    int ret = 1;
    int count = 1;
    int i;
    for(i = 1; i < n; ++i){
        if(A[i] != A[i-1] || count == 1){
            if(A[i] == A[i-1])
                count = 2;
            else 
                count = 1;
            A[ret++] = A[i];
            continue;
        }
        count++;
    }
    return n ? ret : 0;
}
