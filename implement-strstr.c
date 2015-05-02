int strStr(char* haystack, char* needle) {
    int jump[256];
    int nd_len = strlen(needle);
    int ht_len = strlen(haystack);
    int i,j;
    
    for(i = 0; i < 256; ++i)
        jump[i] = nd_len + 1;

    for(i = 0; i < nd_len; ++i)
        jump[needle[i]] = nd_len - i;
        
    for(i = 0; i <= ht_len - nd_len; i += jump[haystack[i+nd_len]]){
        j = 0;
        while(j < nd_len && needle[j] == haystack[i+j])
            ++j;

        if(j == nd_len)
            return i;
    }
    
    return -1;
}
