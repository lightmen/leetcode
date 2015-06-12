class Solution {
public:
    void searchWord(vector<string> &ret, string s, unordered_set<string>& dict,
        int idx, string str, int *dp)
    {
        int len = s.size();
        for(int i = 0; i + idx < len; ++i){
            string substr = s.substr(idx,i+1);
            if(dp[idx+i] && dict.find(substr) != dict.end()){
                if(idx + i < len-1){
                    searchWord(ret,s,dict,idx+i+1,str+substr+" ",dp);
                }else{
                    ret.push_back(str+substr);
                    return ;
                }
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        int *dp = new int[len];
        vector<string> ret;
        memset(dp,0,sizeof(int) * len);

        for(int i = 0; i < len; ++i){
            if(wordDict.find(s.substr(0,i+1)) != wordDict.end()){
                dp[i] = 1;
                continue;
            }
            for(int j = 0; j < i; ++j){
                if(dp[j] && wordDict.find(s.substr(j+1,i-j)) != wordDict.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }

        if(dp[len-1])
            searchWord(ret,s,wordDict,0,"",dp);

        delete[] dp;
        return ret;
    }
};
