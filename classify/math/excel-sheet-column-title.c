char* convertToTitle(int n) {
    char *ret;
    int i;

    ret = (char *)malloc(sizeof(char) * 26);
    memset(ret,0,sizeof(char) * 26);
    i = 24;
    while(n){
        ret[i--] = (n-1) % 26 + 'A';
        n = (n-1) / 26;
    }

    return ret + i + 1;
}
