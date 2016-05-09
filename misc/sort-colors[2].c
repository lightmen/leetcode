void sortColors(int A[], int n) {
    int i,one,two;
    one = 0;
    two = 0;
    for(i = 0; i < n; ++i){
        if(A[i] == 0){
            A[i] = A[two];
            A[two] = A[one];
            A[one] = 0;
            ++one;
            ++two;
        }else if(A[i] == 1){
            A[i] = A[two];
            A[two] = 1;
            two++;
        }
    }
}
