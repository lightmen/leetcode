class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        int size;
        int i,start,end;
        int sum;
        
        sort(nums.begin(),nums.end());
        
        size = nums.size();
        for(i = 0; i < size-2; ++i){
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            
            start = i + 1;
            end = size - 1;
            while(start < end){
                sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    int pos = ret.size() - 1;
                    if(pos >= 0 && ret[pos][0] == nums[i] &&
                        ret[pos][1] == nums[start] && ret[pos][2] == nums[end]){
                        ++start;
                        --end;
                        continue;
                    }
                    
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[start]);
                    tmp.push_back(nums[end]);
                    
                    ret.push_back(tmp);
                    ++start;
                    --end;
                }else if(sum > 0){
                    --end;
                }else{
                    ++start;
                }
            }
        }
        return ret;
    }
};
