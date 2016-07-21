# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        if root is None:
            return True

        node = root.left
        while node and node.right:
            node = node.right

        if node and node.val >= root.val:
            return False

        node = root.right
        while node and node.left:
            node = node.left

        if node and node.val <= root.val:
            return False

        return self.isValidBST(root.left) and self.isValidBST(root.right)
