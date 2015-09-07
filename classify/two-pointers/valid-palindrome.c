int to_lower(int a)
{
    if(a >= 'A' && a <= 'Z')
        return a + 32;
    return a;
}

int is_alpha(int a)
{
    return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') ||
        (a >= '0' && a <= '9');
}

bool isPalindrome(char* s) {
    int i,j;

    i = 0;
    j = strlen(s) - 1;
    while(i < j){
        if(!is_alpha(s[i])){
            i++;
            continue;
        }
        if(!is_alpha(s[j])){
            --j;
            continue;
        }

        if(to_lower(s[i]) != to_lower(s[j]))
            return false;
        ++i;
        --j;
    }

    return true;
}
