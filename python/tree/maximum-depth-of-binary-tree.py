# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def depth(self,root,cur_h):
        if root is None:
            return

        cur_h += 1
        if cur_h > self.max_h:
            self.max_h = cur_h

        self.depth(root.left,cur_h)
        self.depth(root.right,cur_h)

    def maxDepth(self, root):
        self.max_h = 0
        self.depth(root,0)

        return self.max_h
