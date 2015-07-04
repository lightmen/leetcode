/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **ret;
int size;

void helper(char *s, char *ip,int flag)
{
    int n,len,value,ip_len;
    char *tmp;

    len = strlen(s);
    if(flag == 3){
        if(len == 0 || len > 3)
            return ;
        value = atoi(s);
        if(strlen(s) >= 2 && *s == '0')
            return ;
        if(value > 255)
            return ;
        strcat(ip,s);
        ret[size++] = strdup(ip);
        return ;
    }

    ip_len = strlen(ip);
    for(n = 1; n <= 3; ++n){
        if(n > len)
            break;
        tmp = strndup(s,n);
        value = atoi(tmp);
        if(n >= 2 && *tmp == '0')
            continue;
        if(value > 255)
            continue;
        strcat(ip,tmp);
        strcat(ip,".");
        helper(s+n,ip,flag+1);
        *(ip+ip_len) = 0;
        free(tmp);
        tmp = NULL;
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    char *ip;
    size = 0;

    ip = (char *)malloc(sizeof(char) * 16);
    memset(ip,0,sizeof(char) * 16);

    ret = (char **)malloc(sizeof(char*) * 1000);
    helper(s,ip,0);
    *returnSize = size;

    ret = (char **)realloc(ret,sizeof(char *) * size);
    return ret;
}
