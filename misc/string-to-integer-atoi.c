int myAtoi(char *str) {
    int i = 0;
    int len = strlen(str);
    int minus = 0;
    int overflag = 0;
    int tmp = 0;
    int ret = 0;
    
    while(i < len && (str[i] == ' ' || str[i] == '\t'))
        ++i;
        
    if(i < len && str[i] == '-'){
        minus = 1;
        ++i;
    }
    if(i < len && str[i] == '+'){
        if(minus)
            return 0;
        i++;
    }
    
    while(i < len && (str[i] >= '0' && str[i] <= '9')){
        tmp = ret;
        ret = ret * 10 + str[i] - '0';
        if(ret / 10 != tmp){
            overflag = 1;
            break;
        }
        i++;
    }
    
    if(minus)
        ret = -ret;
    if(overflag && minus){
        ret = INT_MIN;
    }else if(overflag){
        ret = INT_MAX;
    }
    
    return ret;
}
