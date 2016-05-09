class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        int i,j,start,end;
        int size;
        int sum;
        
        sort(nums.begin(),nums.end());
        
        size = nums.size();
        for(i = 0; i < size - 3; ++i){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(j = i + 1; j < size - 2; ++j){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                    
                start = j + 1;
                end = size - 1;
                while(start < end){
                    sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if(sum == target){
                        int n = ret.size()-1;
                        if(n >= 0 && ret[n][0] == nums[i] && ret[n][1] == nums[j] &&
                            ret[n][2] == nums[start] && ret[n][3] == nums[end]){
                            ++start;
                            --end;
                            continue;
                        }
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[start]);
                        tmp.push_back(nums[end]);
                        
                        ret.push_back(tmp);
                        ++start;
                        --end;
                    }else if(sum > target){
                        --end;
                    }else{
                        ++start;
                    }
                }
            }
        }
        
        return ret;
    }
};
