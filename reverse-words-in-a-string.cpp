class Solution {
public:
    void reverseWords(string &s) {
        int i,j,k,len;
        int flag;
        string p;
        
        len = s.size();
        flag = 0;
        j = len;
        for(i = len-1; i >= 0; --i){
            if(s[i] == ' ')
                j = i;
            else if(i == 0 || s[i-1] == ' '){
                if(flag)
                    p.push_back(' ');
                for(k = i; k < j; ++k)
                    p.push_back(s[k]);
                flag = 1;
            }
        }
        
        s = p;
    }
};
