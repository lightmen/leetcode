bool isValid(char* s) {
    char *st;
    int len,i;
    int top;
    char ch;

    len = strlen(s);
    st = (char *)malloc(sizeof(char) * len);
    top = -1;
    for(i = 0; i < len; ++i){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st[++top] = s[i];
        else{
            if(top == -1)
                return false;

            ch = st[top--];
            if((ch == '(' && s[i] != ')') || (ch == '[' &&
                s[i] != ']') || (ch == '{' && s[i] != '}'))
                return false;
        }
    }

    free(st);
    return top == -1;
}
