int search(int A[], int n, int target) {
    int mid,begin,end;
    int rotated;
    rotated = n - 1;
    begin = 0;
    end = n - 1;
    while(begin < end){
        mid = (begin + end) / 2;
        if(A[mid] > A[mid + 1]){
            rotated = mid;
            break;
        }else if(A[mid] > A[end]){
            begin = mid + 1;
        }else{
            end = mid;
        }
    }
    
    begin = 0;
    end = rotated;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(A[mid] == target)
            return mid;
        else if(A[mid] > target){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    
    begin = rotated + 1;
    end = n - 1;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(A[mid] == target)
            return mid;
        else if(A[mid] > target){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    
    return -1;
}
