int evalRPN(char** tokens, int tokensSize) {
    int i;
    int ret;
    int *stack;
    int top = 0;

    stack = (int *)malloc(sizeof(int) * tokensSize);

    for(i = 0; i < tokensSize; ++i){
        if(isdigit(tokens[i][0]) || strlen(tokens[i]) > 1){
            stack[top++] = strtol(tokens[i],0,10);
            continue;
        }

        top--;
        switch(tokens[i][0]){
        case '+':
            stack[top-1] += stack[top];
            break;
        case '-':
            stack[top-1] -= stack[top];
            break;
        case '*':
            stack[top-1] *= stack[top];
            break;
        case '/':
            stack[top-1] /= stack[top];
            break;
        default:
            break;
        }
    }

    ret = stack[0];
    free(stack);

    return ret;
}
