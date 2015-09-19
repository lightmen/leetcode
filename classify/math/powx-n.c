double myPow(double x, int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return x;

    int is_neg = 0;
    if(n < 0){
        n = -n;
        is_neg = 1;
    }

    double df = myPow(x,n/2);
    df *= df;
    if(n % 2 == 1)
        df *= x;

    return is_neg ? 1 / df : df;
}
