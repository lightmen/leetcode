int myAtoi(char* str) {
    int is_neg;
    int ret;

    is_neg = 0;
    while(*str && *str == ' ')
        str++;
    if(*str == '+'){
        str++;
    }else if (*str == '-'){
        is_neg = 1;
        str++;
    }

    if(*str < '0' || *str > '9')
        return 0;

    ret = 0;
    while(*str && (*str >= '0' && *str <= '9')){
        int tmp = ret;
        ret = (ret * 10) + *str - '0';
        if(ret / 10 != tmp)
            return is_neg ? INT_MIN : INT_MAX;
        str++;
    }

    return is_neg ? -ret : ret;
}
