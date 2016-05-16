char* removeDuplicateLetters(char* s) {
    char hash[256];
    char visited[256];
    int i = 0;
    char *st;
    int top;

    memset(hash,0,256);
    memset(visited,0,256);

    while(s[i])
        ++hash[s[i++]];

    st = malloc(i + 1);
    top = -1;

    while(*s){
        char ch = *(s++);
        hash[ch]--;
        if(visited[ch])
            continue;

        while(top > -1 && st[top] > ch && hash[st[top]] > 0){
            visited[st[top]] = 0;
            top--;
        }

        st[++top] = ch;
        visited[ch] = 1;
    }

    st[++top] = 0;

    return st;
}
