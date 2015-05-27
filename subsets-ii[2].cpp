class Solution {
public:
    static int my_cmp(vector<int>  v1,vector<int> v2)
    {
        int len1 = v1.size();
        int len2 = v2.size();
        if(len1 == len2){
            for(int i = 0; i < len1; ++i)
                if(v1[i] != v2[i])
                    return 1;
            return 0;
        }
        return 1;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ret;
        int len = nums.size();
        int i,value,count;
        count = 1 << len;

        sort(nums.begin(),nums.end());
        for(i = 0; i < count; ++i){
            vector<int> tmp;
            value = i;
            int j = 0;
            while(value){
                if(value & 0x1)
                    tmp.push_back(nums[j]);
                ++j;
                value >>= 1;
            }
            int r = ret.size();
            int flag = 0;
            for(j = 0; j < r; ++j)
                if(!my_cmp(ret[j],tmp))
                    flag = 1;
            if(!flag)
                ret.push_back(tmp);
        }
        return ret;
    }
};
