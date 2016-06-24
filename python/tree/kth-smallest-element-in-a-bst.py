# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getKth(self,root,k):
        if not root:
            return 0,0

        val,left = self.getKth(root.left,k)
        if left + 1 > k:
            return val,left
        elif left + 1 == k:
            return root.val,k

        val,right =  self.getKth(root.right,k - left - 1)
        return val, left + right + 1

    def kthSmallest(self, root, k):
        val, count = self.getKth(root,k)
        return val
