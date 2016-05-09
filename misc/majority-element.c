int majorityElement(int num[], int n) {
    int ret,count,i;
    count = 0;
    for(i = 0; i < n; ++i){
        if(count == 0) 
            ret = num[i];
        if(ret == num[i])
            count++;
        else
            count--;
    }
    return ret;
}
