char* getHint(char* secret, char* guess) {
    int *ret;
    int a = 0;
    int b = 0;
    int len = strlen(guess);
    int m[256] = {0};
    int *visited = malloc(sizeof(int)*len);

    ret = malloc(sizeof(int) * (len+2));
    memset(visited, 0, sizeof(int)*len);

    for(int i = 0; i < len; ++i){
        if(secret[i] == guess[i]){
            ++a;
            visited[i] = 1;
        }else{
            m[secret[i]]++;
        }
    }

    for(int i = 0; i < len; ++i){
        if(visited[i])
            continue;

        if(m[guess[i]]){
            m[guess[i]]--;
            ++b;
        }
    }

    len = sprintf(ret, "%dA%dB", a, b);
    ret[len] = 0;

    free(visited);
    return ret;
}
