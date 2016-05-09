uint32_t reverseBits(uint32_t n) {
    unsigned int ret = 0;
    int count = 32;
    while(count-- > 0){
        ret = (ret << 1) | (n & 1);
        n = n >> 1;
    }
    
    return ret;
}
