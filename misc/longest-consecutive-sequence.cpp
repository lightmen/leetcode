class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int size = nums.size();
        int ret = 1;
        int cur;
        for(int i = 0; i < size; ++i)
            mp[nums[i]] = 1;
        for(int i = 0; i < size; ++i){
            if(mp[nums[i]]){
                mp[nums[i]] = 0;
                cur = 1;
                int left = nums[i] - 1;
                int right = nums[i] + 1;
                while(mp[left]){
                    mp[left--] = 0;
                    cur++;
                }
                while(mp[right]){
                    mp[right++] = 0;
                    cur++;
                }
                ret = cur > ret ? cur : ret;
            }
        }
        return ret;
    }
};
