char *addBinary(char *a, char *b) {
    char *ret = NULL;
    int a_len,b_len;
    int carry = 0;
    int i = 0;
    a_len = strlen(a);
    b_len = strlen(b);
    ret = (char *)malloc((a_len+b_len + 2) * sizeof(char));
    i = a_len+b_len;
    ret[i--] = 0;
    
    while(a_len > 0 && b_len > 0){
        --a_len;
        --b_len;
        ret[i--] = '0' + (carry + a[a_len] - '0' + b[b_len] - '0') % 2;
        carry = (carry + a[a_len] - '0' + b[b_len] - '0') / 2;
    }
    while(a_len > 0){
        --a_len;
        ret[i--] = '0' + (carry + a[a_len] - '0') % 2;
        carry = (carry + a[a_len] - '0') / 2;
    }
    while(b_len > 0){
        --b_len;
        ret[i--] = '0' + (carry  + b[b_len] - '0') % 2;
        carry = (carry + b[b_len] - '0') / 2;
    }
    
    if(carry){
        ret[i--] = carry + '0';
    }
    
    return ret+i+1;
}
