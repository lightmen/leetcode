int lengthOfLongestSubstring(char* s) {
    int index[256] = {0};
    int last_index = -1;
    int len = strlen(s);
    int ret = 0;

    for(int i = 0; i < len; ++i){
        last_index = index[s[i]] > last_index ? index[s[i]] : last_index;
        index[s[i]] = i + 1;
        ret = (i - last_index + 1) > ret ? (i - last_index + 1) : ret;
    }

    return ret;
}
