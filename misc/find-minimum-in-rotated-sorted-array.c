int findMin(int num[], int n) {
    int beg = 0;
    int end = n - 1;
    int mid = 0;
    while(beg < end){
        mid = (beg + end) / 2;
        if(num[mid] > num[mid + 1])
            return num[mid + 1];
        if(num[mid] > num[beg])
            beg = mid + 1;
        else
            end = mid;
    }
    return num[0];
}
