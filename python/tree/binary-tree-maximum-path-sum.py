# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def max_sum(self,root):
        if not root:
            return (0,-sys.maxint)

        left = self.max_sum(root.left)
        right = self.max_sum(root.right)

        retval = max(left[0]+root.val, right[0]+root.val,0)
        maxval = max(left[1],right[1],root.val+left[0]+right[0])

        return (retval,maxval)

    def maxPathSum(self, root):
        _, nodeval = self.max_sum(root)
        return nodeval
