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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rvv;
        vector<int> vc;
        queue<TreeNode *> qt;
        TreeNode *tmp;
        int n,i;
        if(root == NULL)
            return rvv;
            
        qt.push(root);
        while(!qt.empty()){
            n = qt.size();
            for(i = 0; i < n; ++i){
                tmp = qt.front();
                vc.push_back(tmp->val);
                qt.pop();
                if(tmp->left)
                    qt.push(tmp->left);
                if(tmp->right)
                    qt.push(tmp->right);
            }
            rvv.push_back(vc);
            vc.clear();
        }
        
        return rvv;
    }
};
