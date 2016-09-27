char findTheDifference(char* s, char* t) {
    int hash[256] = {0};
    int len = strlen(s);
    int i;

    for(i = 0; i < len; ++i)
        hash[s[i]]++;

    for(i = 0; i <= len; ++i)
        if(hash[t[i]] == 0)
            break;
        else
            --hash[t[i]];

    return t[i];
}
