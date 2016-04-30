char* intToRoman(int num) {
    char symbols[][3] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I",
    };

    int values[] = {
        1000, 900, 500, 400,
        100,  90,  50,  40,
        10,   9,   5,   4,
        1,
    };

    char *ret;
    int i,j;

    i = 0;
    ret = (char *)malloc(sizeof(char) * 32);
    memset(ret,0,sizeof(char) * 32);

    while(num > 0){
        int k = num / values[i];
        for(j = 0; j < k; ++j)
            strcat(ret,symbols[i]);

        num -= k* values[i];
        i++;
    }

    return ret;
}
