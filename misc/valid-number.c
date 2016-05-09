bool isNumber(char* s) {
    int len;
    int i;
    bool is_number;
    
    len = strlen(s);
    i = 0;
    while(i < len && s[i] == ' ')
        i++;
    if(i < len && (s[i] == '+' || s[i] == '-'))
        i++;
        
    is_number = false;
    while(i < len && (s[i] >= '0' && s[i] <= '9')){
        i++;
        is_number = true;
    }

    if(i < len && s[i] == '.'){
        i++;
        while(i < len && (s[i] >= '0' && s[i] <= '9')){
            is_number = true;
            i++;
        }
    }

    if(i < len && is_number && s[i] == 'e'){
        i++;
        if(s[i] == '+' || s[i] == '-')
            i++;
        is_number = false;
        while(i < len && (s[i] >= '0' && s[i] <= '9')){
            is_number = true;
            i++;
        }
    }

    while(i < len && s[i] == ' ')
        i++;
        
    return is_number && i == len;
}
