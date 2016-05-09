int searchInsert(int A[], int n, int target) {
    int beg,end,mid;
    beg = 0;
    end = n-1;
  
    while(beg <= end){
        mid = (beg + end) / 2;
        if(A[mid] == target)
            return mid;
        else if(A[mid] > target)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return beg;
}
