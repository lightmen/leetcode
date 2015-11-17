int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int pos;

    while(len > 0 && s[len-1] == ' ')
        --len;

    pos = len - 1;
    while(pos >= 0 && s[pos] != ' ')
        --pos;

    return len - pos - 1;
}
