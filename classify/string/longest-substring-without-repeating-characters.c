int lengthOfLongestSubstring(char* s) {
    int index[256];
    int last_index;
    int len,i,ret;

    memset(index,0,sizeof(int) * 256);
    last_index = -1;
    len = strlen(s);

    ret = 0;
    for(i = 0; i < len; ++i){
        last_index = index[s[i]] > last_index ? index[s[i]] : last_index;
        index[s[i]] = i + 1;
        ret = (i - last_index + 1 > ret) ? i - last_index + 1 : ret;
    }

    return ret;
}
