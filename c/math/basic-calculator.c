#define NUM 1000

int calculate(char* s) {
    char op[NUM];
    int val[NUM];
    int top_op,top_val;
    int value = 0;

    top_op = top_val = -1;
    while(*s){
        if(*s == ' '){
            ++s;
            continue;
        }

        if(*s == '+' || *s == '-' || *s == '('){
            op[++top_op] = *s;
            ++s;
            continue;
        }

        if(*s == ')'){
            top_op--;
            value = val[top_val--];
            s++;
        }else{
            value = 0;
            while(isdigit(*s)){
                value = value * 10 + (*s - '0');
                s++;
            }
        }

        if(top_op > -1 && op[top_op] != '('){
            switch(op[top_op]){
            case '+':
                value = val[top_val] + value;
                break;
            case '-':
                value = val[top_val] - value;
                break;
            }
            top_op--;
            top_val--;
        }

        val[++top_val] = value;
    }

    return val[top_val];
}
