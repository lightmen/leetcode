char *convertToTitle(int n) {
    int i = 0;
    char *ret = (char *)malloc(sizeof(char) * 15);
    i = 14;
    ret[i--] = '\0';
    while(n){
        ret[i--] = (n-1) % 26 + 'A';
        n = (n-1)/26;
    }
    
    return ret+i+1;
}
