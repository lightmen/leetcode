char* intToRoman(int num) {
    int values[] = {
        1000, 900, 500, 400,
        100,  90,  50,  40,
        10,   9,   5,   4,
        1
    };

    char symbols[13][3] = {
        "M",  "CM",  "D",  "CD",
        "C",  "XC",  "L",  "XL",
        "X",  "IX",  "V",  "IV",
        "I"
    };

    int i;
    char *ret;
    ret = (char *)malloc(sizeof(char) * 50);
    memset(ret,0,sizeof(char) * 50);

    i = 0;
    while(num > 0){
        if(num >= values[i]){
            strcat(ret,symbols[i]);
            num -= values[i];
            continue;
        }
        i++;
    }

    return ret;
}
