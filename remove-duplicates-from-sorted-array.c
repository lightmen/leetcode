int removeDuplicates(int A[], int n) {
    int i,j;
    i = 0;
    j = 0;
    while(j < n){
        A[i++] = A[j++];
        while(j < n && A[j] == A[j-1])
            ++j;
    }
    return i;
}
