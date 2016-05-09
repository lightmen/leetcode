int calculate(char* s) {
    int ret = 0;
    int cur = 0;
    int tmp;
    char op = 0;
    int type = 1;

    while(*s){
        if(isdigit(*s)){
            tmp = 0;
            while(isdigit(*s)){
                tmp = tmp * 10 + (*s - '0');
                s++;
            }

            if(op == '+' || op == '-'){
                ret += (type * cur);
                cur = tmp;
                type = ((op == '+') ? 1 : -1);
            }else if(op == '*'){
                cur *= tmp;
            }else if(op == '/'){
                cur /= tmp;
            }else{
                cur = tmp;
            }

            continue;
        }

        if(*s == ' ')
            goto out;

        op = *s;
out:
        s++;
    }

    ret += (type * cur);
    return ret;
}
