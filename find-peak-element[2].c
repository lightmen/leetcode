int findPeakElement(int num[], int n) {
    int begin = 0;
    int end = n-1;
    int mid = 0;
    while(begin < end){
        mid = (begin + end) / 2;
        if(num[mid] < num[mid+1])
            begin = mid+1;
        else
            end = mid;
    }
    return begin;
}
