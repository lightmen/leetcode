int reverse(int x) {
    int rx = 0;
    int ret = 0;
    while(x){
        ret = rx * 10 + x % 10;
        if(ret / 10 != rx){
            ret = 0;
            break;
        }
        rx = ret;
        x /= 10;
    }

    return ret;
}
