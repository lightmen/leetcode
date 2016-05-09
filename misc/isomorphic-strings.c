bool isIsomorphic(char* s, char* t) {
    int flag[256],visited[256];
    int i,len;
    len = strlen(s);
    
    memset(flag,0,sizeof(int) * 256);
    memset(visited,0,sizeof(int) * 256);

    for(i = 0; i < len; ++i){
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
