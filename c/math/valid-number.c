bool isNumber(char* s) {
    int len;
    int i,e;
    bool num = false;
    bool exp = false;
    bool dot = false;
    i = 0;
    len = strlen(s);
    e = len - 1;

    while(i <= e && s[i] == ' ')
        i++;

    if(i > len - 1)
        return false;

    while(e >= i && s[e] == ' ')
        e--;

    if(s[i] == '+' || s[i] == '-')
        i++;

    while(i <= e){
        char c = s[i];

        if(isdigit(c)){
            num = true;
        }else if(c == '.'){
            if(exp || dot)
                return false;
            dot = true;
        }else if(c == 'e'){
            if(exp || !num)
                return false;
            num = false;
            exp = true;
        }else if(c == '+' || c == '-'){
            if(s[i-1] != 'e')
                return false;
        }else{
            return false;
        }

        i++;
    }

    return num;
}
