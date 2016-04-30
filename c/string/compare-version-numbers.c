int compareVersion(char* version1, char* version2) {
    int len1, len2;
    int v1,v2;
    int i,j;

    len1 = strlen(version1);
    len2 = strlen(version2);
    i = j = 0;
    v1 = v2 = 0;
    while(v1 == v2 && (i < len1 || j < len2)){
        while(version1[i] != '.' && i < len1){
            v1 = v1 * 10 + version1[i] - '0';
            i++;
        }
        while(version2[j] != '.' && j < len2){
            v2 = v2 * 10 + version2[j] - '0';
            j++;
        }

        if(v1 != v2)
            break;
        v1 = v2 = 0;
        i++;
        j++;
    }

    return v1 == v2 ? 0 : (v1 > v2 ? 1 : -1);
}
