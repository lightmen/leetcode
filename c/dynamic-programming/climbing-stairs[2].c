int climbStairs(int n) {
    int d1,d2;
    int i,ret;

    d1 = 0;
    d2 = 1;
    ret = 1;
    for(i = 1; i <= n; ++i){
        ret = d1 + d2;
        d1 = d2;
        d2 = ret;
    }

    return ret;
}
