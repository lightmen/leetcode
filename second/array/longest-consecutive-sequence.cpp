class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> umap;
        int ret = 0;
        int size = nums.size();

        for(int i = 0; i < size; ++i)
            umap[nums[i]] = true;

        for(int i = 0; i < size; ++i){
            int up = nums[i];
            while(umap.find(up) != umap.end()){
                umap.erase(up);
                up++;
            }

            int down = nums[i] - 1;
            while(umap.find(down) != umap.end()){
                umap.erase(down);
                down--;
            }

            if(up - down - 1 > ret)
                ret = up - down - 1;
        }

        return ret;
    }
};
