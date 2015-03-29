static inline int is_match(const char a, const char b)
{
    return ((a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']'));
}
bool isValid(char *s) {
    int len;
    int i;
    int top;
    char *stack = NULL;
    
    if(s == NULL)
        return true;
        
    len = strlen(s);
    stack = (char *)malloc(sizeof(char) * len);
    
    top = -1;
    i = 0;
    
    while(i < len){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            top++;
            stack[top] = s[i];
        }else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(top < 0 || !is_match(stack[top],s[i]))
                return false;
            top--;
        }else
            return false;
        i++;
    }
    
    if(top != -1)
        return false;
        
    return true;
}
