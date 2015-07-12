int countDigitOne(int n) {
    int ret = 0;
    long m;

    for(m = 1; m <= n; m *= 10){
        long a = n / m;
        long b = n % m;
        ret += (a + 8) / 10 * m;
        if(a % 10 == 1)
            ret += (b + 1);
    }

    return ret;
}
