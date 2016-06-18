# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.result = []

    def dfs(self,root,dp):
        if not root:
            return
        if len(self.result) <= dp:
            self.result.append(root.val)
        else:
            self.result[dp] = root.val
        self.dfs(root.left,dp+1)
        self.dfs(root.right,dp+1)

    def rightSideView(self, root):
        self.dfs(root,0)
        return self.result
