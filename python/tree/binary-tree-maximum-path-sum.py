# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def max_sum(self,root,nodeval):
        if not root:
            return (0,nodeval)

        left,nodeval = self.max_sum(root.left,nodeval)
        right,nodeval = self.max_sum(root.right,nodeval)

        retval = root.val
        retval += left if left > right else right

        cur_max = root.val + left + right
        nodeval = cur_max if cur_max > nodeval else nodeval

        return (retval if retval > 0 else 0, nodeval)

    def maxPathSum(self, root):
        nodeval = -sys.maxint - 1
        retval, nodeval = self.max_sum(root,nodeval)
        return nodeval
