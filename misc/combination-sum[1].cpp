class Solution {
public:
    void rec(vector<vector<int> > &vret, vector<int> &vt, vector<int> &cand,
                int index, int sum, int target)
    {
        if(sum > target)
            return ;
        if(sum == target){
            vret.push_back(vt);
            return ;
        }
        int size = cand.size();
        for(int i = index; i < size; ++i){
            vt.push_back(cand[i]);
            rec(vret,vt,cand,i,sum+cand[i],target);
            vt.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > vret;
        vector<int> vt;

        sort(candidates.begin(),candidates.end());
        rec(vret,vt,candidates,0,0,target);
        return vret;
    }
};
