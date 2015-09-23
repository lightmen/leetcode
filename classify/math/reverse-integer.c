int reverse(int x) {
    long rx = 0;
    long lx = x;
    int is_neg = 0;

    if(lx < 0){
        lx = -lx;
        is_neg = 1;
    }

    while(lx){
        rx = 10 * rx + lx % 10;
        lx /= 10;
    }

    rx = is_neg ? -rx : rx;
    if(rx > INT_MAX || rx < INT_MIN)
        return 0;

    return rx;
}
