int mySqrt(int x) {
    int i,tmp;
    long begin = 0;
    long end = x;
    long mid;
    if(x == 1)
        return 1;
    while(begin < end){
        mid = (begin + end) / 2;
        if(mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x))
            return mid;
        if(mid * mid < x)
            begin = mid;
        else
            end = mid;
            
    }
    return 0;
}
