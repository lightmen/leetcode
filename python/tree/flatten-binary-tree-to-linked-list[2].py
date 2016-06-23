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

        while root:
            if root.left:
                node = root.left
                while node.right:
                    node = node.right

                node.right = root.right
                root.right = root.left
                root.left = None

            root = root.right
