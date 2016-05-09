int lengthOfLastWord(char *s) {
    int len = strlen(s);
    int i = len -1;
    int ret = 0;
    while(i >= 0 && s[i] == ' ')
        i--;
    while(i >= 0 && s[i] != ' '){
        ret++;
        i--;
    }
    
    return ret;
}
