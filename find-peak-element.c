int findPeakElement(int num[], int n) {
    int i = 0;
    while(i < n-1){
        if(num[i] > num[i+1])
            return i;
        else
            i++;
    }
}
