char* getHint(char* secret, char* guess) {
    int *ret;
    int a = 0;
    int b = 0;
    int len = strlen(guess);
    int m[256] = {0};

    ret = malloc(sizeof(int) * (len+2));

    for(int i = 0; i < len; ++i){
        if(secret[i] == guess[i]){
            ++a;
        }else{
            m[secret[i]]++;
        }
    }

    for(int i = 0; i < len; ++i){
        if(secret[i] != guess[i] && m[guess[i]]){
            m[guess[i]]--;
            ++b;
        }
    }

    len = sprintf(ret, "%dA%dB", a, b);
    ret[len] = 0;

    return ret;
}
