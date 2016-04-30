int lengthOfLastWord(char* s) {
    int start;
    int end,last;

    start = -1;
    end = 0;
    last = strlen(s);

    while(last > 0 && s[last-1] == ' ')
        --last;

    while(end < last){
        if(s[end] == ' ')
            start = end;
        end++;
    }

    return end - start - 1;
}
