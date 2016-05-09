/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **ret;
int size;

int cmp(char *a, char *b, int n)
{
    int i;
    for(i = 0; i < n; ++i)
        if(a[i] != b[i])
            return a[i] - b[i];
    return 0;
}

int is_valid(char *s,int len)
{
    if(len == 1 && cmp(s,"0",len) >= 0 &&
        cmp(s,"9",len) <= 0)
        return 1;
    if(len == 2 && cmp(s,"10",len) >= 0 &&
        cmp(s,"99",len) <= 0)
        return 1;
    if(len == 3 && cmp(s,"100",len) >= 0 &&
        cmp(s,"255",len) <= 0)
        return 1;

    return 0;
}

void helper(char *s, char *ip,int flag)
{
    int n,len,ip_len;
    char *tmp;

    len = strlen(s);
    if(flag == 3){
        if(!is_valid(s,len))
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
        if(!is_valid(tmp,n))
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
