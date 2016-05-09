class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> m;
        map<string,int> count;
        vector<int> ret;
        int words_size = words.size();
        int word_len = words[0].size();
        int s_len = s.size();
        int i,j;
        
        for(i = 0; i < words_size; ++i)
            m[words[i]]++;
            
        for(i = 0; i <= s_len - words_size * word_len; ++i){
            count.clear();
            for(j = 0; j < words_size; ++j){
                string sub = s.substr(i+j*word_len,word_len);
                if(m.find(sub) == m.end())
                    break;
                count[sub]++;
                if(count[sub] > m[sub])
                    break;
            }
            if(j == words_size)
                ret.push_back(i);
        }
        
        return ret;
    }
};
