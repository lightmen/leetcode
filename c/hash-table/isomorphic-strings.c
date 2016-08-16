bool isIsomorphic(char* s, char* t) {
    int flag[256] = {0};
    int visited[256] = {0};
    int len = strlen(s);

    for(int i = 0; i < len; ++i){
        if(flag[s[i]] == 0){
            if(visited[t[i]])
                return false;

            flag[s[i]] = t[i];
            visited[t[i]] = 1;
        }else if(flag[s[i]] != t[i]){
            return false;
        }
    }

    return true;
}
