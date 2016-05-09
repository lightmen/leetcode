class Solution {
public:
    bool is_equal(vector<int> &va, vector<int> &vb)
    {
        int size = va.size();
        if(size != vb.size())
            return false;
        for(int i = 0; i < size; ++i)
            if(va[i] != vb[i])
                return false;
        return true;
    }

    void rec(vector<vector<int> > &vret, vector<int> &cand, vector<int> &vt, int target)
    {
        int size = cand.size();
        for(int i = 0; i < size; ++i){
            if(target < cand[i])
                continue;
            if(target == cand[i]){
                vt.push_back(target);
                vector<int> tmp(vt.begin(),vt.end());
                vt.pop_back();
                int vsize = vret.size();
                int i;
                sort(tmp.begin(),tmp.end());
                for(i = 0; i < vsize; ++i)
                    if(is_equal(vret[i],tmp))
                        break;
                if(i == vsize)
                    vret.push_back(tmp);

                break;
            }

            vt.push_back(cand[i]);
            rec(vret,cand,vt,target-cand[i]);
            vt.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > vret;
        vector<int> vt;

        sort(candidates.begin(),candidates.end());
        rec(vret,candidates,vt,target);

        return vret;
    }
};
