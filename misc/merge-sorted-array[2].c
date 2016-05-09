void merge(int A[], int m, int B[], int n) {
    int i,j,k;
    i = m - 1;
    j = n - 1;
    k = m + n -1;
    while(i >= 0 && j >= 0)
        A[k--] = A[i] > B[j] ? A[i--] : B[j--]; 
    
    while(j >= 0)
        A[k--] = B[j--];
}
