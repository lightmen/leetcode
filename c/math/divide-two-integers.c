iint divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long a = labs(dividend);
    long b = labs(divisor);
    bool is_neg = ((dividend > 0 && divisor < 0)
                || (dividend < 0 && divisor > 0));
    int ret = 0;
    while(a >= b){
        int tmp = 0;
        while(a >= (b << tmp))
            tmp++;
        a -= (b << (tmp - 1));
        ret += (1 << (tmp - 1));
    }

    return is_neg ? -ret : ret;
}
