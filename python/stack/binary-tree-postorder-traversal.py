# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        if root is None:
            return []
        return self.postorderTraversal(root.left) +\
            self.postorderTraversal(root.right) + [root.val]
