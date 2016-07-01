# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):


    def pathSum(self, root, sum):
        def dfs(root,sum,cur_arr):
            if root.left is None and root.right is None:
                if root.val == sum:
                    result.append(cur_arr)
            else:
                if root.left:
                    dfs(root.left, sum - root.val,cur_arr + [root.left.val])
                if root.right:
                    dfs(root.right, sum - root.val,cur_arr + [root.right.val])

        result = []
        if root:
            dfs(root,sum,[root.val])

        return result
