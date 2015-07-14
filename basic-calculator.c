int calculate(char* s) {
    int ret = 0;
    int top = 0;
    int stack[1000];
    int tmp;
    int type = 1;

    while(*s){
        if(isdigit(*s)){
            tmp = 0;
            while(*s && isdigit(*s)){
                tmp = tmp * 10 + (*s - '0');
                s++;
            }
            ret += (type * tmp);
            continue;
        }

        if(*s == '-'){
            type = -1;
         }else if(*s == '+'){
             type = 1;
         }else if(*s == '('){
             stack[top++] = ret;
             ret = 0;
             stack[top++] = type;
             type = 1;
         }else if(*s == ')'){
             type = stack[--top];
             ret = stack[--top] + type * ret;
         }
         s++;
    }

    return ret;
}
