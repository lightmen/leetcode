char* minWindow(char* s, char* t) {
    int i, start = 0;
    int s_len = strlen(s);
    int t_len = strlen(t);
    int min_index, min_window = s_len + 1;
    int cur_match = 0;
    char *ret = "";
    int t_map[256] = {0};
    int cur_map[256] = {0};

    for(i = 0; i < t_len; ++i)
        t_map[t[i]]++;

    for(i = 0; i < s_len; ++i){
        if(t_map[s[i]] == 0)
            continue;

        cur_map[s[i]]++;
        if(cur_map[s[i]] <= t_map[s[i]])
            cur_match++;

        if(cur_match != t_len)
            continue;

        while(!t_map[s[start]] ||
            cur_map[s[start]] > t_map[s[start]]){
            if(t_map[s[start]])
                cur_map[s[start]]--;
            start++;
        }

        if(i - start + 1 < min_window){
            min_window = i - start + 1;
            min_index = start;
        }
        cur_map[s[start]]--;
        start++;
        cur_match--;
    }

    if(min_window != s_len + 1){
        ret = malloc(sizeof(char) * (min_window + 1));
        memcpy(ret, s + min_index, min_window);
        ret[min_window] = 0;
    }

    return ret;
}
