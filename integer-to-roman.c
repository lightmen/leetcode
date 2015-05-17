char* intToRoman(int num) {
    int values[] = {
        1000, 900, 500, 400,
        100,  90,  50,  40,
        10,   9,   5,   4, 
        1
    };
    
    char symbols[13][3] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    };
    
    char *ret = (char *)malloc(sizeof(char) * 32);
    int i = 0,j,cur,len;
    memset(ret,0,sizeof(char) * 32);
    
    cur = 0;
    while(num > 0){
        int k = num / values[i];
        for(j = 0; j < k; ++j){
            len = strlen(symbols[i]);
            strncat(ret + cur,symbols[i],len);
            cur += len;
            num -= values[i];
        }
        i++;
    }
    return ret;
}
