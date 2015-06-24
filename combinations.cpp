class Solution {
public:
    void rec(vector<vector<int> > &vret, vector<int> &vt,
						int l,int p, int n, int k)
    {
        if(l == k){
            vret.push_back(vt);
        }else{
            for(int i = p; i <= n; ++i){
                vt.push_back(i);
                rec(vret,vt,l+1,i+1,n,k);
                vt.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > vret;
        vector<int> vt;
        rec(vret,vt,0,1,n,k);

        return vret;
    }
};
