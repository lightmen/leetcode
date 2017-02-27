int is_pattern(char *d[], char c, char *word)
{
    if(strcmp(d[c-'a'], word) != 0)
        return false;

    for(int i = 0; i < 26; ++i)
        if(d[i] && strcmp(d[i], word) == 0 && 'a' + i != c)
            return false;

    return true;
}

bool wordPattern(char* pattern, char* str) {
    char *d[26];
    char *sep = " ";
    char *word;
    int i = 0;
    char c;
    int len = strlen(pattern);
    memset(d, 0, sizeof(char *) * 26);
    word = strtok(str, sep);
    while(word != NULL){
        if(i >= len)
            return false;
        c = pattern[i++];
        if(d[c - 'a'] == NULL)
            d[c - 'a'] = strdup(word);

        if(!is_pattern(d, c, word))
            return false;
        word = strtok(NULL, sep);
    }

    if(i != len)
        return false;

    return true;
}
