char* convert(char* s, int numRows) {
    char **arr;
    char *ret;
    int *index;
    int i,j,k;
    int len = strlen(s);
    
    //alloc and init the ret,arr and index pointer
    ret = (char *)malloc(sizeof(char) * (len + 1));
    arr = (char **)malloc(sizeof(char *) * numRows);
    for(i = 0; i < numRows; ++i){
        arr[i] = (char *)malloc(sizeof(char) * len);
        memset(arr[i],0,sizeof(char) * len);
    }
    index = (int *)malloc(sizeof(int) * numRows);
    memset(index,0,sizeof(int) * numRows);
    
    i = 0;
    k = numRows - 2;
    while(i < len){
        for(j = 0; i < len && j < numRows; ++j)
            arr[j][index[j]++] = s[i++];
        for(j = k; i < len && j > 0; --j)
            arr[j][index[j]++] = s[i++];
    }

    k = 0;
    for(i = 0; i < numRows; ++i){
        len = strlen(arr[i]);
        for(j = 0; j < index[i]; ++j)
            ret[k++] = arr[i][j];
        free(arr[i]);
    }
    free(arr);
    free(index);

    ret[k] = '\0';
    return ret;
}
