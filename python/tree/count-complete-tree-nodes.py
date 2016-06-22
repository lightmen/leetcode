# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        if not root:
            return 0

        lh = 0
        tmp = root
        while tmp:
            lh += 1
            tmp = tmp.left

        rh = 0
        tmp = root
        while tmp:
            rh += 1
            tmp = tmp.right

        if lh == rh:
            return (1 << lh) - 1

        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
