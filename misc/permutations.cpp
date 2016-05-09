class Solution {
public:
    void rec(vector<vector<int>>& vret, vector<int>& nums, vector<int>& vt,
            int size, int *flag, int count)
    {
        if(count == size){
            vret.push_back(vt);
        }else{
            for(int i = 0; i < size; ++i){
                if(!flag[i]){
                    flag[i] = 1;
                    vt.push_back(nums[i]);
                    rec(vret,nums,vt,size,flag,count+1);
                    vt.pop_back();
                    flag[i] = 0;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > vret;
        vector<int> vt;
        int len = nums.size();
        int *flag = new int[len];
        memset(flag,0,sizeof(int)*len);
        rec(vret,nums,vt,len,flag,0);

        delete[] flag;
        return vret;
    }
};
