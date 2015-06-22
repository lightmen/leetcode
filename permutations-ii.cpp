class Solution {
public:
    int size;
    int k;
    void rec(vector<vector<int>> &vret, int *mem,
            vector<int> &vt,int *c,int count)
    {
        if(count == size){
            vret.push_back(vt);
        }else{
            for(int i = 0; i < k; ++i){
                if(c[i] > 0){
                    c[i]--;
                    vt.push_back(mem[i]);
                    rec(vret,mem,vt,c,count+1);
                    vt.pop_back();
                    c[i]++;
                }
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int i,j;
        int *mem;
        vector<vector<int>> vret;
        vector<int> vt;
        int *c;

        size = nums.size();
        c = new int[size];
        memset(c,0,sizeof(int)*size);
        mem = new int[size];

        k = 0;
        for(i = 0; i < size; ++i){
            for(j = 0; j < k; ++j)
                if(mem[j] == nums[i]){
                    c[j]++;
                    break;
                }
            if(j == k){
                mem[k] = nums[i];
                c[k] = 1;
                k++;
            }
        }

        rec(vret,mem,vt,c,0);

        delete[] mem;
        delete[] c;
        return vret;
    }
};
