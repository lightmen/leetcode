# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        if not root:
            return None

        node = self.invertTree(root.left)
        root.left = self.invertTree(root.right)
        root.right = node

        return root
