int lengthOfLongestSubstring(char* s) {
    int index[256];
    int i = 0;
    int len = strlen(s);
    int last_pos = -1,longest = 0;

    memset(index,0,sizeof(int)*256);

    for(i = 0; i < len; ++i){
        last_pos = index[s[i]] > last_pos ? index[s[i]] : last_pos;
        index[s[i]] = i+1;
        longest = i - last_pos + 1 > longest ? i - last_pos + 1 : longest;
    }
    
    return longest;
}
