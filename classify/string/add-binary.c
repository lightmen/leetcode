char* addBinary(char* a, char* b) {
    char *ret;
    int la,lb,lr;
    int i,j,k;
    int carry = 0;
    int value;

    la = strlen(a);
    lb = strlen(b);
    lr = (la > lb ? la : lb) + 2;

    ret = (char *)malloc(sizeof(char) * lr);
    ret[lr-1] = 0;
    k = lr-2;
    i = la - 1;
    j = lb - 1;
    while(i >= 0 && j >= 0){
        value = (a[i--] - '0') + (b[j--] - '0')  + carry;
        carry = value / 2;
        value %= 2;
        ret[k--] = '0' + value;
    }

    if(j >= 0){
        i = j;
        a = b;
    }

    while(i >= 0){
        value = (a[i--] - '0') + carry;
        carry = value / 2;
        value %= 2;
        ret[k--] = '0' + value;
    }

    if(carry)
        ret[k--] = '1';

    return ret + k + 1;
}
