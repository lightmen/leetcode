bool isValid(char* s) {
    char *st;
    int len;
    int top = -1;

    len = strlen(s);
    st = malloc(len);

    while(*s){
        if(*s == '(' || *s == '{' || *s == '['){
            st[++top] = *s;
        }else if( *s == ')' && st[top] == '('){
            --top;
        }else if(*s == '}' && st[top] == '{'){
            --top;
        }else if(*s == ']' && st[top] == '['){
            --top;
        }else{
            return false;
        }

        s++;
    }

    return top == -1;
}
