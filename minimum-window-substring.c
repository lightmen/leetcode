char* minWindow(char* s, char* t) {
    int i,start,end;
    int s_len = strlen(s);
    int t_len = strlen(t);
    int min_index,min_window = s_len + 1;
    int cur_window = 0;
    int init_map[256],map[256];
    char *ret = "";
    
    memset(init_map,0,sizeof(int) * 256);
    memset(map,0,sizeof(int)*256);

    for(i = 0; i < t_len; ++i){
        init_map[t[i]]++;
    }
    
    start = 0;
    end = 0;
    for(end = 0; end < s_len; ++end){
        if(init_map[s[end]]){
            map[s[end]]++;
            if(map[s[end]] <= init_map[s[end]]){ 
                cur_window++;
            }
            if(cur_window == t_len){
                while(!init_map[s[start]] || 
                        map[s[start]] > init_map[s[start]]){
                    if(init_map[s[start]])
                        map[s[start]]--;
                    start++;
                }
                
                if(end - start + 1 < min_window){
                    min_window = end - start + 1;
                    min_index = start;
                }
                map[s[start]]--;
                start++;
                cur_window--;
            }
        }
    }
    
    if(min_window != s_len + 1){
        ret = (char *)malloc(sizeof(char) * (min_window + 1));
        memcpy(ret,s+min_index,min_window);
        ret[min_window] = '\0';
    }
    
    return ret;
}
