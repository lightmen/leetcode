# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        if p and q:
            if p.val != q.val:
                return False

            return self.isSameTree(p.left,q.left) and \
                self.isSameTree(p.right,q.right)

        return p is None and q is None
