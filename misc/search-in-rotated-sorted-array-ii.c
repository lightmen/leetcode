bool search(int A[], int n, int target) {
    int begin,end,mid;
    begin = 0;
    end = n - 1;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(A[mid] == target)
            return true;
        if(A[mid] > A[end]){
            if(A[mid] > target && A[begin] <= target)
                end = mid - 1;
            else
                begin = mid + 1;
        }else if(A[mid] < A[end]){
            if(A[mid] < target && A[end] >= target)
                begin = mid + 1;
            else
                end = mid - 1;
        }else{
            --end;
        }
    }
    
    return false;
}
