# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        if n == 0:
            return []
        return self.dfs(1,n)

    def dfs(self,start,end):
        if start > end:
            return [None]
        ret = []
        for val in range(start, end+1):
            left = self.dfs(start, val-1)
            right = self.dfs(val+1,end)
            for i in left:
                for j in right:
                    root = TreeNode(val)
                    root.left = i
                    root.right = j
                    ret.append(root)

        return ret
