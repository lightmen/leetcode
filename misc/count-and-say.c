const int num = 10000; 
char *countAndSay(int n) {
    char *s;
    char *tmp;
    int i;
    int step = 0;
    int cur;
    int len;
    int pos;
    s = (char *)malloc(sizeof(char) * num);
    tmp = (char *)malloc(sizeof(char) * num);
    
    if(n <= 0)
        return NULL;
        
    s[1] = '\0';
    s[0] = '1';
    step++;
    while(step < n){
        len = strlen(s);
        cur = 0;
        i = 0;
        while(i < len){
            pos = i;
            while(pos+1 < len && s[pos] == s[pos+1])
                pos++;
            tmp[cur] = pos - i + 1 + '0';
            i += pos - i + 1;
            cur++;
            tmp[cur] = s[pos];
            cur++;
            tmp[cur] = '\0';
        }
        strcpy(s,tmp);
        step++;
    }
    
    return s;
}
