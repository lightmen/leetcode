int titleToNumber(char *s) {
    int ret = 0;
    int len;
    int i = 0;
    len = strlen(s);
    while(i < len){
        ret = ret * 26 + s[i] - 'A' + 1;
        i++;
    }
    return ret;
}
