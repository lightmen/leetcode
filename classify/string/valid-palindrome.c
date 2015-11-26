bool is_equal(int a, int b)
{
    if(a >= 'A' && a <= 'Z')
        a = a - 'A' + 'a';
    if(b >= 'A' && b <= 'Z')
        b = b - 'A' + 'a';
    return a == b;
}

bool isPalindrome(char* s) {
    int start, end;

    start = 0;
    end = strlen(s) - 1;
    while(start < end){
        if(!isalpha(s[start]) && !isdigit(s[start])){
            start++;
            continue;
        }
        if(!isalpha(s[end]) && !isdigit(s[end])){
            --end;
            continue;
        }
        if(!is_equal(s[start], s[end]))
            return false;
        ++start;
        --end;
    }

    return true;
}
