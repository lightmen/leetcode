static int expand(char *s, int start, int end){
    while(start >= 0 && s[end] && s[start] == s[end]){
        --start;
        ++end;
    }
    return end - start - 1;
}
char* longestPalindrome(char* s) {
    int i;
    int len = strlen(s);
    int index,max;
    char *ret;
    max = 0;
    for(i = 0; i < len; ++i){
        int len1 = expand(s,i,i);
        int len2 = expand(s,i,i+1);
        int len = len1 > len2 ? len1 : len2;
        if(len > max){
            max = len;
            index = i - (len - 1) / 2;
        }
    }
    
    ret = (char *)malloc(sizeof(char) * (max + 1));
    i = 0;
    while(i < max){
        ret[i] = s[i+index];
        i++;
    }
    ret[max] = '\0';
    
    return ret;
}
