class Solution {
public:
    int size;
    vector<vector<int> > vret;

    void rec(vector<int> &vt, vector<int> &cand,int target, int index)
    {
        if(target == 0){
            vret.push_back(vt);
            return ;
        }

        if(index >= size || target < 0)
            return ;

        int prev = -1;
        for(int i = index; i < size; ++i){
            if(cand[i] > target)
                break;
            if(cand[i] == prev)
                continue;

            prev = cand[i];
            vt.push_back(cand[i]);
            rec(vt,cand,target-cand[i],i+1);
            vt.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vt;
        sort(candidates.begin(),candidates.end());
        size = candidates.size();

        rec(vt,candidates,target,0);

        return vret;
    }
};
