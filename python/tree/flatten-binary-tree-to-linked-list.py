# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        if not root:
            return

        left = root.left
        right = root.right

        root.left = None
        root.right = left

        self.flatten(left)
        self.flatten(right)

        while root.right:
            root = root.right

        root.right = right
