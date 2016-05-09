class Solution {
public:
    int size;
    int tar;
    vector<vector<int> > vret;

    void rec(vector<int> &vt, vector<int> &cand,int sum, int index)
    {
        if(sum > tar)
            return ;
        if(sum == tar){
            vret.push_back(vt);
            return ;
        }

        int prev = -1;
        for(int i = index; i < size; ++i){
            if(cand[i] == prev)
                continue;
            prev = cand[i];
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
