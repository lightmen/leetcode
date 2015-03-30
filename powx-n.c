double myPow(double x, int n) {
    int nagative = 0;
    double ret,tmp;
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(n < 0){
        nagative = 1;
        n = -n;
    }
    tmp = myPow(x,n/2);
    ret = tmp * tmp;
    if(n % 2){
        ret *= x;
    }
    if(nagative)
        ret = 1 / ret;
    return ret;
}
