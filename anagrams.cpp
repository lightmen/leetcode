class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ret;
        map<string,string> mp;
        map<string,string>::iterator mit;
        string str_eof = "0";
        int len;
        len = strs.size();
        for(int i = 0; i < len; ++i){
            string key = strs[i];
            sort(key.begin(),key.end());

            mit = mp.find(key);
            if( mit == mp.end()){
                mp.insert(pair<string,string>(key,strs[i]));
                continue;
            }

            if(mit->second != str_eof){
                ret.push_back(mit->second);
                mp[key] = str_eof;
            }

            ret.push_back(strs[i]);
        }

        return ret;
    }
};
