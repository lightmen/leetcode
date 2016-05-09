int reverse(int x) {
    long long ret = 0;
    long long a = x;
    int positive_flag = 1;
    if(x < 0){
        positive_flag = -1;
        a = -x;
    }
    while(a){
        ret = ret * 10 + a % 10;
        a /= 10;
    }

    if(ret > 0x7fffffff || ret < (-0x7fffffff - 1))
        return 0;

    return positive_flag * ret;
}
