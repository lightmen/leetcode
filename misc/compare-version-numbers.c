int compareVersion(char *version1, char *version2){
    int va = 0;
    int vb = 0;
    int i,j;
    int len1,len2;
    len1 = strlen(version1);
    len2 = strlen(version2);
    i = 0;
    j = 0;
    while(va == vb && (i < len1 || j < len2)){
        while(i < len1 && version1[i] != '.'){
            va = va * 10 + version1[i] - '0';
            i++;
        }
        while(j < len2 && version2[j] != '.'){
            vb = vb * 10 + version2[j] - '0';
            j++;
        }
        if(va != vb)
            break;
        va = 0;
        vb = 0;
        i++;
        j++;
    }
    
    if(va > vb)
            return 1;
    else if(va < vb)
            return -1;
    return 0;
}
