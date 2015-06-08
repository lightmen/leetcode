ar* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
        return "";
    int len0 = strlen(strs[0]);
    char *prefix = (char *)malloc(sizeof(char) * (len0 + 1));
    memset(prefix,0,sizeof(char) * (len0 + 1));
    int i,j;
    for(i = 0; i < len0; ++i){
        for(j = 1; j < strsSize; ++j)
            if(strs[j][i] != strs[0][i])
                break;
        if(j != strsSize)
            break;
        prefix[i] = strs[0][i];
    }

    return prefix;
}
