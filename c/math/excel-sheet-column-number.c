int titleToNumber(char* s) {
    int ret = 0;
    while(*s){
        ret = ret * 26 + (*s - 'A' + 1);
        s++;
    }
    return ret;
}
