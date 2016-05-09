bool isPowerOfTwo(int n) {
    int count = 0;

    while(n > 0){
        count += (n & 0x1);
        n >>= 1;
    }

    return count == 1;
}
