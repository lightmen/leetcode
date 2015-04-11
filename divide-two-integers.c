int divide(int dividend, int divisor) {
    int ret;
    int is_neg;
    int cnt = 0;
    long dd,dr;
    is_neg = ((dividend ^ divisor) >> 31) ? 1 : 0;
    ret = 0;
    dr = fabs(divisor);
    dd = fabs(dividend);
    while(dr <= dd){
        dr <<= 1;
        cnt++;
    }
    while(cnt >= 0){
        if(dd >= dr){
            dd -= dr;
            ret += (1 << cnt);
        }
        cnt--;
        dr >>= 1;
    }
    if(ret == INT_MIN){
        return is_neg ? INT_MIN : INT_MAX;
    }
    return is_neg ? -ret : ret;
}
