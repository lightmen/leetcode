int expand(char *s, int start, int end)
{
    while(start >= 0 && s[end] && s[start] == s[end]){
        --start;
        ++end;
    }
    return end - start - 1;
}

char* longestPalindrome(char* s) {
    int max,t1,t2,tmax,len,index;
    int i;
    char *ret;

    len = strlen(s);
    max = 0;
    for(i = 0; i < len; ++i){
        t1 = expand(s,i,i);
        t2 = expand(s,i,i+1);
        tmax = t1 > t2 ? t1 : t2;
        if(tmax > max){
            max = tmax;
            index = i - (tmax - 1) / 2;
        }
    }

    ret = (char *)malloc(sizeof(char) * (max + 1));
    i = 0;
    while(i < max){
        ret[i] = s[index + i];
        i++;
    }
    ret[max] = 0;

    return ret;
}
