static void reverse(char *s, int start, int end)
{
    while(start < end){
        char tmp = s[end];
        s[end] = s[start];
        s[start] = tmp;
        ++start;
        --end;
    }
}

static int trim(char *s)
{
    int start,end;
    int flag;
    start = 0;
    end = 0;

    flag = 0;
    while(s[end]){
        while(s[end] && s[end] == ' ')
            ++end;
        if(!s[end])
            break;
        if(flag && s[end-1] == ' ')
            s[start++] = ' ';

        s[start++] = s[end];
        ++end;
        flag = 1;
    }
    s[start] = '\0';
    return start;
}

void reverseWords(char *s) {
    int i,j,len;
    int start;

    len = trim(s);
    j = len;
    for(i = len-1; i >= 0; --i){
        if(i == 0 || s[i-1] == ' '){
            reverse(s,i,j-1);
            j = i-1;
        }
    }
    
    reverse(s,0,len-1);
}
