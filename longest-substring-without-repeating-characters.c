int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int max = 0;
    int flag[256];
    int i,j;
    
    for(i = 0; i < len; ++i){
        memset(flag,0,sizeof(int) * 256);
        j = 0;
        while(i+j < len && !flag[s[i+j]]){
            flag[s[i+j]] = 1;
            j++;
            if(j > max)
                max = j;
        }
    }
    
    return max;
}
