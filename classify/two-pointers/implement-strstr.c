int strStr(char* haystack, char* needle) {
    int step[256];
    int i,j;
    int nd_len = strlen(needle);
    int ht_len = strlen(haystack);

    for(i = 0; i < ht_len; ++i)
        step[haystack[i]] = nd_len + 1;

    for(i = 0; i < nd_len; ++i)
        step[needle[i]] = nd_len - i;

    for(i = 0; i <= ht_len - nd_len; i += step[haystack[i+nd_len]]){
        j = 0;
        while(j < nd_len && haystack[j+i] == needle[j])
            ++j;
        if(j == nd_len)
            return i;
    }

    return -1;
}
