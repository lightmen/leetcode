int myAtoi(char* str) {
    int ret = 0;
    int tmp = 0;
    int is_neg = 1;

    while(*str && *str == ' ')
        str++;

    if(*str == '-')
        is_neg = -1;

    if(*str == '+' || *str == '-')
        str++;

    while(*str >= '0' && *str <= '9'){
        tmp = ret * 10 + (*str - '0');
        str++;
        if(tmp / 10 != ret)
            return is_neg == -1 ? INT_MIN : INT_MAX;
        ret = tmp;
    }

    return is_neg * ret;
}
