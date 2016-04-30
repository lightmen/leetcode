int strStr(char* haystack, char* needle) {
    int jump[256];
    int i,j;
    int ht_len,nd_len;

    ht_len = strlen(haystack);
    nd_len = strlen(needle);

    for(i = 0; i < ht_len; ++i)
        jump[haystack[i]] = nd_len + 1;
    for(i = 0; i < nd_len; ++i)
        jump[needle[i]] = nd_len - i;

    for(i = 0; i <= ht_len - nd_len; i += jump[haystack[i+nd_len]]){
        j = 0;
        while(j < nd_len && haystack[i+j] == needle[j])
            j++;
        if(j == nd_len)
            return i;
    }

    return -1;
}
