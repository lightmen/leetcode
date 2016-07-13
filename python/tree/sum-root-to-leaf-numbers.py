# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sum(self, root, cur_val):
        if root is None:
            return 0

        val = cur_val * 10 + root.val
        if root.left is None and root.right is None:
            return val

        return self.sum(root.left,val) + self.sum(root.right,val)

    def sumNumbers(self, root):
        return self.sum(root,0)
