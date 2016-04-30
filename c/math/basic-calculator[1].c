int calculate(char* s) {
    int stack[1000];
    int value;
    int top = -1;
    int ret = 0;
    int type = 1;

    while(*s){
        if(isdigit(*s)){
            value = 0;
            while(isdigit(*s)){
                value = value * 10 + *s - '0';
                s++;
            }

            ret += (type * value);
        }

        if(*s == '+'){
            type = 1;
        }else if(*s == '-'){
            type = -1;
        }else if(*s == '('){
            stack[++top] = ret;
            stack[++top] = type;
            ret = 0;
            type = 1;
        }else if(*s == ')'){
            type = stack[top--];
            ret = stack[top--] + type * ret;
        }

        s++;
    }

    return ret;
}
