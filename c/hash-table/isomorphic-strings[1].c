bool isIsomorphic(char* s, char* t) {
    int ms[256] = {0};
    int mt[256] = {0};

    int len = strlen(s);

    for(int i = 0; i < len; ++i){
        if((ms[s[i]] && ms[s[i]] !=  t[i]) ||
            (mt[t[i]] && mt[t[i]] != s[i]))
            return false;

        ms[s[i]] = t[i];
        mt[t[i]] = s[i];
    }

    return true;
}
