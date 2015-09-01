int lengthOfLongestSubstring(char* s) {
    int index[256];
    int last_pos = -1;
    int i;
    int ret = 0;
    int len;

    memset(index,0,sizeof(int) * 256);
    len = strlen(s);
    for(i = 0; i < len; ++i){
        last_pos = index[s[i]] > last_pos ? index[s[i]] : last_pos;
        index[s[i]] = i+1;
        ret = (i - last_pos + 1) > ret ? (i - last_pos + 1) : ret;
    }

    return ret;
}
