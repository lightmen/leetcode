bool isMatch(char* s, char* p) {
    if(*p == 0)
        return *s == 0;

    if(p[1] != '*')
        return ((*p == *s) || (*p == '.' && *s != 0))
                && isMatch(s+1,p+1);

    while((*s == *p) || (*p == '.' && *s != 0)){
        if(isMatch(s,p+2))
            return true;
        s++;
    }

    return isMatch(s,p+2);
}
