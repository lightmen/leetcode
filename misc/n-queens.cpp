class Solution {
public:
    vector<vector<string>> vret;
    bool is_ok(int *queue, int k, int pos)
    {
        for(int i = 0; i < k; ++i)
            if(queue[i] == pos || abs(pos - queue[i]) == (k - i))
                return false;

        return true;
    }

    int helper(int *queue, int n, int k)
    {
        int i;
        if(n == k){
            vector<string> vs;
            for(i = 0; i < n; ++i){
                string s(n,'.');
                s[queue[i]] = 'Q';
                vs.push_back(s);
            }
            vret.push_back(vs);
        }

        for(i = 0; i < n; ++i){
            if(!is_ok(queue,k,i))
                continue;
            queue[k] = i;
            helper(queue,n,k+1);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int *queue = new int[n];

        helper(queue,n,0);

        free(queue);
        return vret;
    }
};
