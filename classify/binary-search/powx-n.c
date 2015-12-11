double myPow(double x, int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return x;

    int is_neg = 0;
    if(n < 0){
        is_neg = 1;
        n = -n;
    }

    double half = myPow(x,n/2);
    double ret;

    if(n % 2)
        ret = x * half * half;
    else
        ret = half * half;

    return is_neg ? 1/ret : ret;
}
