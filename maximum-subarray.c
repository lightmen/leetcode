int maxSubArray(int A[], int n) {
    int max,tmp,i;
    max = A[0];
    tmp = 0;
    for(i = 0;i < n; ++i){
        tmp += A[i];
        if(tmp > max)
            max = tmp;
        if(tmp < 0)
            tmp = 0;
    }
    return max;
}
