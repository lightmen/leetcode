class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        bool *flag = new bool[len];
        bool ret;
        memset(flag,0,sizeof(bool) * len);

        for(int i = 0; i < len; ++i){
            if(wordDict.find(s.substr(0,i+1)) != wordDict.end()){
                flag[i] = true;
                continue;
            }
            for(int j = 0; j < i; ++j){
                if(flag[j] &&
                    wordDict.find(s.substr(j+1,i-j)) != wordDict.end()){
                    flag[i] = true;
                    break;
                }
            }
        }

        ret = flag[len-1];
        delete flag;

        return ret;
    }
};
