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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vi;
        stack<TreeNode *> st;
        TreeNode *tmp;
        if(!root)
            return vi;
        tmp = root;
        while(tmp || !st.empty()){
            while(tmp){
                st.push(tmp);
                vi.push_back(tmp->val);
                tmp = tmp->left;
            }
            tmp = st.top();
            st.pop();
            tmp = tmp->right;
        }
        return vi;
    }
};
