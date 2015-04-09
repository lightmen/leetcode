double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int *arr;
    int num,i,j,k;
    num = m + n;
    i = 0; 
    j = 0;
    k = 0;
    arr = (int *)malloc(sizeof(int) * num);
    while(i < m && j < n){
        if(A[i] < B[j]){
            arr[k++] = A[i++];
        }else{
            arr[k++] = B[j++];
        }
    }
    while(i < m){
        arr[k++] = A[i++];
    }
    while(j < n){
            arr[k++] = B[j++];
    }
    
    if(num & 0x1){
        return arr[num/2];
    }else{
        return (double)(arr[(num-1)/2] + arr[num/2]) / 2;
    }
}
