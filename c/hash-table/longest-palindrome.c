int longestPalindrome(char* s) {
    int map[256] = {0};
    int i,len,ret = 0;
    int plus = 0;

    len = strlen(s);
    for(i = 0; i < len; ++i)
        map[s[i]]++;

    for(i = 0; i < 256; ++i){
        ret += map[i];
        if(map[i] % 2 == 1){
            plus = 1;
            ret--;
        }
    }

    return ret + plus;
}
