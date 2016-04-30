char* longestCommonPrefix(char** strs, int strsSize) {
    int i,j;
    int len;

    if(strsSize == 0)
        return "";

    len = strlen(strs[0]);
    for(i = 0; i < len; ++i){
        for(j = 1; j < strsSize; ++j)
            if(strs[j][i] != strs[0][i])
                return strndup(strs[0],i);
    }

    return strndup(strs[0],i);
}
