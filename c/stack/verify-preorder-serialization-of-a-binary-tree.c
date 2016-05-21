bool isValidSerialization(char* preorder) {
    int count = 0;
    char *next = preorder;
    char *left,*right;

    if(*next && *next != '#')
        count++;

    while (count-- > 0){
        while(*next && *next != ',')
            next++;
        if(*next)
            next++;
        left = next;
        if(!*left)
            return false;

        while(*next && *next != ',')
            next++;
        if(*next)
            next++;
        right = next;
        if(!*right)
            return false;

        if(*left != '#')
            count++;
        if(*right != '#')
            count++;
    }
    while(*next && *next != ',')
            next++;
    if(*next)
        return false;

    return true;
}
