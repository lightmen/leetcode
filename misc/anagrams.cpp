class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ret;
        map<string,int> mp;
        int len;

        len = strs.size();
        for(int i = 0; i < len; ++i){
            string key = strs[i];
            sort(key.begin(),key.end());

            if( mp.find(key) == mp.end()){
                mp.insert(pair<string,int>(key,i));
                continue;
            }

            if(mp[key] >= 0){
                ret.push_back(strs[mp[key]]);
                mp[key] = -1;
            }

            ret.push_back(strs[i]);
        }

        return ret;
    }
};
