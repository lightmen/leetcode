int findMin(int num[], int n) {
    int mid,begin,end;
    begin = 0;
    end = n - 1;
    while(begin <= end){
        mid = (begin + end) / 2;
        if(mid -1 >= 0 && num[mid] < num[mid - 1])
            return num[mid];
        else if(num[mid] > num[end])
            begin = mid + 1;
        else if(num[mid] < num[end])
            end = mid - 1;
        else
            end--;
    }
    
    return num[0];
}
