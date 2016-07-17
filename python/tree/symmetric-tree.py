# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSame(self, left, right):
        if left and right:
            if left.val != right.val:
                return False

            return self.isSame(left.left,right.right) and \
                self.isSame(left.right,right.left)

        return left is None and right is None

    def isSymmetric(self, root):
        if root is None:
            return True

        return self.isSame(root.left,root.right)
