bool isIsomorphic(char* s, char* t) {
    int ms[256] = {0};
    int mt[256] = {0};

    int len = strlen(s);

    for(int i = 0; i < len; ++i){
        if(ms[s[i]] != mt[t[i]])
            return false;

        ms[s[i]] = i + 1;
        mt[t[i]] = i + 1;
    }

    return true;
}
