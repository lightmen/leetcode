/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > rvv;
        queue<TreeNode *> qt;
        vector<int> vi;
        TreeNode *tmp;
        int i,n;
        
        if(root == NULL)
            return rvv;
            
        qt.push(root);
        while(!qt.empty()){
            n = qt.size();
            vi.clear();
            for(i = 0; i < n; ++i){
                tmp = qt.front();
                qt.pop();
                vi.push_back(tmp->val);
                if(tmp->left)
                    qt.push(tmp->left);
                if(tmp->right)
                    qt.push(tmp->right);
            }
            rvv.push_back(vi);
        }
        
        reverse(rvv.begin(),rvv.end());
        
        return rvv;
    }
};
