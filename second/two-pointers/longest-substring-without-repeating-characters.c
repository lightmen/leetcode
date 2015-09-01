int lengthOfLongestSubstring(char* s) {
    int buf[256];
    int start,end;
    int len;
    int ret = 0;
    int i;
    memset(buf,0,sizeof(int) * 256);

    start = 0;
    end = 0;
    len = strlen(s);

    while(end < len){
        if(buf[s[end]] != 0){
            for(i = start; i < buf[s[end]]-1; ++i)
                buf[s[i]] = 0;
            start = buf[s[end]];
        }

        buf[s[end]] = end + 1;
        if(end - start + 1 > ret)
            ret = end - start + 1;

        end++;
    }

    return ret;
}
