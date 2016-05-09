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
    vector<vector<int> > ret;
    void get_sum(TreeNode *root,int sum,vector<int>& v){
        if(root){
            v.push_back(root->val);
            if(root->val == sum && root->left == NULL && root->right == NULL){
                ret.push_back(v);
                v.pop_back();
                return ;
            }
            if(root->left)
                get_sum(root->left,sum-root->val,v);
            if(root->right)
                get_sum(root->right,sum - root->val,v);
            v.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> v;
        get_sum(root,sum,v);
        return ret;
    }
};
