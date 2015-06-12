class Solution {
public:
    void searchWord(vector<string> &ret, string& s, unordered_set<string>& dict,
        int idx, string str, int *dp)
    {
        int size = s.size();
        for(int len = 1; len + idx <= size; ++len){
            string substr = s.substr(idx,len);
            if(dp[idx+len] && dict.find(substr) != dict.end()){
                if(idx + len < size){
                    searchWord(ret,s,dict,idx+len,str+substr+" ",dp);
                }else{
                    ret.push_back(str+substr);
                    return ;
                }
            }

        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        int *dp = new int[len+1];
        vector<string> ret;
        memset(dp,0,sizeof(int) * (len+1));

        dp[0] = 1;
        for(int i = 0; i < len; ++i){
            if(dp[i]){
                for(int l = 1; i+l <= len; ++l){
                    if(wordDict.find(s.substr(i,l)) != wordDict.end())
                        dp[i+l] = 1;
                }
            }
        }

        if(dp[len])
            searchWord(ret,s,wordDict,0,"",dp);

        delete[] dp;
        return ret;
    }
};
