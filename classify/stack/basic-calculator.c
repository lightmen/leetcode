int get_value(int left, int right, int op)
{
    if(op == '-')
        return left - right;
    else if(op == '+')
        return left + right;

    return 0;
}

int calculate(char* s) {
    int *op_st;
    int *val_st;
    int op_top;
    int val_top;
    int left,right;
    int len;
    int tmp;
    int op;

    len = strlen(s);

    op_st = malloc(sizeof(int) * len);
    val_st = malloc(sizeof(int) * len);
    op_top = val_top = -1;

    while(*s){
        if(*s == ' '){
            s++;
            continue;
        }

        if(isdigit(*s)){
            tmp = 0;
            while(isdigit(*s)){
                tmp = 10 * tmp + *s - '0';
                s++;
            }
            val_st[++val_top] = tmp;
            continue;
        }

        switch(*s){
            case '+':
            case '-':
                if(op_top > -1  && (op_st[op_top] == '+' ||
                    op_st[op_top] == '-')){
                    right = val_st[val_top--];
                    left = val_st[val_top--];
                    tmp = get_value(left, right, op_st[op_top--]);
                    val_st[++val_top] = tmp;
                }

                op_st[++op_top] = *s;
                break;
            case '(':
                op_st[++op_top] = *s;
                break;
            case ')':
                while(op_top > -1 && ((op = op_st[op_top--]) != '(')){
                    right = val_st[val_top--];
                    left = val_st[val_top--];
                    tmp = get_value(left, right, op);
                    val_st[++val_top] = tmp;
                }
                break;
            default:
                break;
        }
        s++;
    }

    while(op_top > -1){
        right = val_st[val_top--];
        left = val_st[val_top--];
        tmp = get_value(left, right, op_st[op_top--]);
        val_st[++val_top] = tmp;
    }

    tmp = val_st[val_top];
    free(op_st);
    free(val_st);

    return tmp;
}
