class Solution {
public:
    void dfs(string s, vector<vector<string> > &vret, vector<string> &vs)
    {
        int size = s.size();
        if(size < 1){
            vret.push_back(vs);
            return ;
        }

        for(int i = 0; i < size; ++i){
            int begin = 0;
            int end = i;
            bool is_pal = true;

            while(begin < end){
                if(s[begin] != s[end]){
                    is_pal = false;
                    break;
                }
                ++begin;
                --end;
            }

            if(is_pal){
                vs.push_back(s.substr(0,i+1));
                dfs(s.substr(i+1),vret,vs);
                vs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > vret;
        vector<string> vs;

        dfs(s,vret,vs);

        return vret;
    }
};
