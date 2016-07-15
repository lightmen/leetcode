# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inOrder(self,root):
        if root is None:
            return

        self.inOrder(root.left)

        if self.prev and self.prev.val > root.val:
            self.t2 = root
            if self.t1 is None:
                self.t1 = self.prev

        self.prev = root;

        self.inOrder(root.right)

    def recoverTree(self, root):
        self.prev = None
        self.t1 = None
        self.t2 = None

        self.inOrder(root)

        self.t1.val, self.t2.val = self.t2.val,self.t1.val
