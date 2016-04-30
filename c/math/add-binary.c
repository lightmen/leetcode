char* addBinary(char* a, char* b) {
    char *ret;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = (len_a > len_b ? len_a : len_b) + 2;
    int i,carry;
    int ai,bi;
    int value;

    ret = (char *)malloc(sizeof(char) * max_len);
    memset(ret,0,sizeof(char) * max_len);
    carry = 0;
    ai = len_a - 1;
    bi = len_b - 1;
    i = max_len - 2;
    while(ai >= 0 && bi >= 0){
        value = (a[ai--] - '0') + (b[bi--] - '0')  + carry;
        carry = value / 2;
        value %= 2;
        ret[i--] = '0' + value;
    }

    if(bi >= 0){
        ai = bi;
        a = b;
    }

    while(ai >= 0){
        value = (a[ai--] - '0')   + carry;
        carry = value / 2;
        value %= 2;
        ret[i--] = '0' + value;
    }

    if(carry)
        ret[i--] = '1';
    return ret+i+1;
}
