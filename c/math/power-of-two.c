bool isPowerOfTwo(int n) {
    int ret = 0;
    while(n > 0){
        ret += n & 0x1;
        n >>= 1;
    }

    return ret == 1;
}
