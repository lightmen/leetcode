bool isMatch(char* s, char* p) {
    int lens, lenp;
    int index_s, index_p;
    int back;
    int prev_s, prev_p;

    lens = strlen(s);
    lenp = strlen(p);
    index_s = 0;
    index_p = 0;
    back = 0;

    while(index_s < lens){
        if(index_p < lenp && (p[index_p] == '?' || p[index_p] == s[index_s])){
            index_s++;
            index_p++;
        }else if(p[index_p] == '*'){
            while(index_p < lenp && p[index_p] == '*')
                index_p++;

            if(index_p == lenp)
                return true;

            back = 1;
            prev_s = index_s;
            prev_p = index_p;
        }else if(back){
            prev_s++;
            index_s = prev_s;
            index_p = prev_p;
        }else{
            return false;
        }
    }

    while(index_p < lenp && p[index_p] == '*')
        index_p++;

    return index_p == lenp;
}
