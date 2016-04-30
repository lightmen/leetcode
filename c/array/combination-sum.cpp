class Solution {
public:
    vector<vector<int> > vret;
    void helper(vector<int> &vi, vector<int>& candidates, int index, int diff)
    {
        if(diff == 0){
            vret.push_back(vi);
            return ;
        }

        int size = candidates.size();
        for(int i = index; i < size; ++i){
            if(candidates[i] > diff)
                break;
            vi.push_back(candidates[i]);
            helper(vi,candidates,i,diff-candidates[i]);
            vi.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vi;
        sort(candidates.begin(),candidates.end());
        helper(vi,candidates,0,target);
        return vret;
    }
};
