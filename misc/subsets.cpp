class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        int len = nums.size();
        int num = 1 << len;
        int i,k,value;
        sort(nums.begin(),nums.end());
        for(i = 0; i < num; ++i){
            vector<int> tmp;
            k = 0;
            value = i;
            while(value){
                if(value & 0x1)
                    tmp.push_back(nums[k]);
                value >>= 1;
                ++k;
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
