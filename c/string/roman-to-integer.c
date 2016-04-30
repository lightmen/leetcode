int romanToInt(char* s) {
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

    int i = 0;
    int ret = 0;
    int len;

    while(*s && i < 13){
        len = strlen(symbols[i]);
        if(!strncmp(s,symbols[i],len)){
            ret += values[i];
            s += len;
            continue;
        }
        i++;
    }

    return ret;
}
