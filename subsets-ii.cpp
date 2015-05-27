class Solution {
public:
    static int my_cmp(vector<int>  v1,vector<int> v2)
    {
        int len1 = v1.size();
        int len2 = v2.size();
        if(len1 == len2){
            for(int i = 0; i < len1; ++i)
                if(v1[i] != v2[i])
                    return v1[i] < v2[i];
            return 0;
        }
        return len1 < len2;
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
            ret.push_back(tmp);
        }
        
        sort(ret.begin(),ret.end(),my_cmp);
        vector<vector<int> >::iterator vit = unique(ret.begin(),ret.end());
        ret.erase(vit,ret.end());
        
        return ret;
    }
};
