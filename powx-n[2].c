double myPow(double x, int n) {
    double tmp;
    if(n == 0)
        return 1;
    tmp = myPow(x,n/2);
    if(n % 2)
        return n < 0 ? 1 / x * tmp * tmp : x * tmp * tmp;
    return tmp * tmp;
}
