class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size+1,false);
        dp[0] = true;
        for(int i = 0; i < size; ++i){
            if(dp[i]){
                for(int len = 1; len + i <= size; ++len){
                    if(wordDict.find(s.substr(i,len)) != wordDict.end())
                        dp[i+len] = true;
                }
            }
        }

        return dp[size];
    }
};
