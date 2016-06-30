# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        if root is None:
            return False

        if root.left is None and root.right is None:
            return root.val == sum

        bleft = self.hasPathSum(root.left, sum - root.val)

        return bleft if bleft else self.hasPathSum(root.right, sum - root.val)
