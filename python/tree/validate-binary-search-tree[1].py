# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.lastnode = None

    def isValidBST(self, root):
        if root is None:
            return True

        if not self.isValidBST(root.left):
            return False

        if self.lastnode != None and self.lastnode.val >= root.val:
            return False

        self.lastnode = root
        return self.isValidBST(root.right)
