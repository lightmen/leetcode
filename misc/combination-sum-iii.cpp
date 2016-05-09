class Solution {
public:
    void helper(vector<vector<int> > &vret, vector<int> &vt, int k, int n, int index)
    {
        if(n == 0 && k == 0){
            vret.push_back(vt);
            return ;
        }

        if(index > 9 || n <= 0 || k <= 0)
            return ;

        for(int i = index; i <= 9; ++i){
            if(i > n)
                break;
            vt.push_back(i);
            helper(vret,vt,k-1,n-i,i+1);
            vt.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > vret;
        vector<int> vt;

        helper(vret,vt,k,n,1);

        return vret;
    }
};
