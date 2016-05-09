ass Solution {
public:
    static void subsets(vector<vector<int>> &ret, vector<int> &nums, vector<int> &tmp, int begin)
    {
        ret.push_back(tmp);
        int len = nums.size();
        for(int i = begin; i < len; ++i){
            if(i == begin || nums[i] != nums[i-1]){
                tmp.push_back(nums[i]);
                subsets(ret,nums,tmp,i+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ret;
        vector<int> tmp;
        subsets(ret,nums,tmp,0);
        return ret;
    }
    
};
