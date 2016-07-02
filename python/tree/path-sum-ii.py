# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self,root,sum,cur_arr):
        if root.left is None and root.right is None:
            if root.val == sum:
                self.result.append(cur_arr)
        else:
            if root.left:
                self.dfs(root.left, sum - root.val,cur_arr + [root.left.val])
            if root.right:
                self.dfs(root.right, sum - root.val,cur_arr + [root.right.val])


    def pathSum(self, root, sum):
        self.result = []

        if root:
            self.dfs(root,sum,[root.val])

        return self.result
