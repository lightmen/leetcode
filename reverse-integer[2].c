int reverse(int x) {
    char tmp[50];
    char ch;
    int i,j,len;
    long ret;
    sprintf(tmp,"%d",x);
    len = strlen(tmp);
    i = 0;
    j = len-1;
    while(i < j){
        if(tmp[i] == '-'){
            i++;
            continue;
        }
        ch = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = ch;
        
        i++;
        j--;
    }
    
    i = 0; 
    if(tmp[i] == '-')
        i++;
    while(i < len && tmp[i] == '0')
        i++;
        
    if(tmp[0] == '-'){
        i--;
        if(i > 0)
            tmp[i] = '-';
    }
        
    sscanf(tmp+i,"%ld",&ret);
    if(ret > INT_MAX || ret < INT_MIN)
        return 0;
    
    return (int)ret;
}
