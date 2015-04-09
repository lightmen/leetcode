int *searchRange(int A[], int n, int target) {
    int *ret;
    int mid,begin,end;
    ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = -1;
    ret[1] = -1;
    
    begin = 0;
    end = n - 1;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(A[mid] == target && (mid-1 < 0 || A[mid-1] < target)){
            ret[0] = mid;
            break;
        }else if(A[mid] >= target){
            end = mid - 1;
        }else{ 
            begin = mid + 1;
        }
    }
    
    begin = 0;
    end = n - 1;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(A[mid] == target && (mid + 1 >= n || A[mid + 1] > target)){
            ret[1] = mid;
            break;
        }else if(A[mid] > target){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    
    return ret;
}
