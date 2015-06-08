class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i = 0,cnt = 0,size;
        vector<vector<int> > vret;
        vector<int> vi,prev;

        vi.push_back(1);
        vret.push_back(vi);

        while(cnt < rowIndex){
            prev = vret[cnt++];
            size = prev.size();
            vi.clear();
            vi.push_back(1);
            for(i = 0; i < size-1; ++i)
                vi.push_back(prev[i] + prev[i+1]);
            vi.push_back(1);

            vret.push_back(vi);
        }

        return vi;
    }
};
