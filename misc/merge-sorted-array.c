void merge(int A[], int m, int B[], int n) {
    int i,j;
    int cnt = 0;
    i = m + n -1;
    for(j = m-1; j >= 0; --j,--i)
        A[i] = A[j];
    i++;
    j = 0;
    while(j < n && i < m + n){
        if(A[i] <= B[j])
            A[cnt] = A[i++];
        else
            A[cnt] = B[j++];
        cnt++;
    }
    while(j < n)
        A[cnt++] = B[j++];
    while(i < m + n)
        A[cnt++] = A[i++];
}
