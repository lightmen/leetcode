int removeElement(int A[], int n, int elem) {
    int i,next;
    next = 0;
    for(i = 0; i < n; ++i)
        if(A[i] != elem)
            A[next++] = A[i];
            
    return next;
}
