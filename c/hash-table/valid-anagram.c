bool isAnagram(char* s, char* t) {
    int hash[26] = {0};
    int s_len = strlen(s);
    int t_len = strlen(t);
    int i;
    if(s_len != t_len)
        return false;

    for(i = 0; i < s_len; ++i)
        hash[s[i] - 'a']++;
    for(i = 0; i < t_len; ++i)
        hash[t[i] - 'a']--;

    for(i = 0; i < 26; ++i)
        if(hash[i])
            return false;

    return true;
}
