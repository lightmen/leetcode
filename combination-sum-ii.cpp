class Solution {
public:
    int size;
    int tar;
    vector<vector<int> > vret;
    bool is_equal(vector<int> &va, vector<int> &vb)
    {
        int len = va.size();
        if(len != vb.size())
            return false;
        for(int i = 0; i < len; ++i)
            if(va[i] != vb[i])
                return false;
        return true;
    }

    void rec(vector<int> &vt, vector<int> &cand,int sum, int index)
    {
        if(sum > tar)
            return ;
        if(sum == tar){
            int i,len;
            len = vret.size();
            for(i = 0; i < len; ++i)
                if(is_equal(vret[i],vt))
                    break;
            if(i == len)
                vret.push_back(vt);
            return ;
        }

        for(int i = index; i < size; ++i){
            vt.push_back(cand[i]);
            rec(vt,cand,sum+cand[i],i+1);
            vt.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vt;
        sort(candidates.begin(),candidates.end());
        size = candidates.size();
        tar = target;

        rec(vt,candidates,0,0);

        return vret;
    }
};
