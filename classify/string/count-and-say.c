char* countAndSay(int n) {
    char *ret;
    char *tmp;
    int num = 10000;
    int index = 1;
    int i,j,count,value,len;

    ret = (char *)malloc(sizeof(char) * num);
    tmp = (char *)malloc(sizeof(char) * num);
    memset(ret,0,sizeof(char) * num);
    ret[0] = '1';

    while(index < n){
        i = 0;
        j = 0;
        len = strlen(ret);
        while(i < len){
            value = ret[i++];
            count = 1;
            while(i < len && ret[i] == value){
                i++;
                count++;
            }
            tmp[j++] = count + '0';
            tmp[j++] = value;
        }
        tmp[j] = 0;
        strcpy(ret,tmp);
        index++;
    }

    free(tmp);
    return ret;
}
