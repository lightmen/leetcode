class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int len = strs.size();
        if(len == 0)
            return prefix;
        int len0 = strs[0].size();
        int i,j;

        for(i = 0; i < len0; ++i){
            for(j = 1; j < len; ++j){
                if(strs[j][i] != strs[0][i]){
                    break;
                }
            }
            if(j != len)
                break;
            prefix += strs[0][i];
        }

        return prefix;
    }
};
