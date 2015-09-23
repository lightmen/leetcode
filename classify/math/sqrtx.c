int mySqrt(int x) {
    long start,end,mid;
    start = 0;
    end = x;
    mid = 0;

    if(x == 1)
        return 1;

    while(start < end){
        mid = (start + end) / 2;
        if(mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x))
            break;
        if(mid * mid < x)
            start = mid;
        else
            end = mid;
    }

    return mid;
}
