int longestValidParentheses(char* s) {
    int *stack;
    int *match;
    int top;
    int len = strlen(s);
    int i;
    int cur_len,max_len;

    stack = (int *)malloc(sizeof(int) * len);
    match = (int *)malloc(sizeof(int) * len);
    memset(match,0,sizeof(int)*len);

    top = -1;
    for(i = 0; i < len; ++i){
        if(s[i] == '('){
            top++;
            stack[top] = i;
        }else if(top > -1){
            match[i] = 1;
            match[stack[top]] = 1;
            top--;
        }
    }

    max_len = cur_len = 0;
    for(i = 0; i < len; ++i){
        if(match[i])
            cur_len++;
        else
            cur_len = 0;
        max_len = cur_len > max_len ? cur_len : max_len;
    }

    free(stack);
    free(match);
    return max_len;
}
