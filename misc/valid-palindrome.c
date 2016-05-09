static inline int is_character(const char c)
{
    return ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

static inline int is_match(char a, char b)
{
    if(a >= 'A' && a <= 'Z')
        a = a - 'A' + 'a';
    if(b >= 'A' && b <= 'Z')
        b = b - 'A' + 'a';
    return a == b;
}

bool isPalindrome(char *s) {
    int i,j;
    int len;
    if(s == NULL)
        return true;
        
    len = strlen(s);
    i = 0; 
    j = len -1;
    while(i < j){
        if(!is_character(s[i])){
            i++;
            continue;
        }
        if(!is_character(s[j])){
            j--;
            continue;
        }
        if(!is_match(s[i],s[j]))
            return false;
        i++;
        j--;
    }
    
    if(i < j)
        return false;
        
    return true;
}
