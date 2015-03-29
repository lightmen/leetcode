int removeElement(int A[], int n, int elem) {
    int begin,end;
    int tmp;
    begin = 0;
    end = n-1;

    while(begin <= end){
        while(end >= 0 && A[end] == elem)
            end--;
        while(begin <= n-1 && A[begin] != elem)
            begin++;
            
        if(begin < end){
            tmp = A[begin];
            A[begin] = A[end];
            A[end] = tmp;
        }
    }
    
    return begin;
}
