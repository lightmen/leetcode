# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lca(self,root,node,flag):
        if root is None or self.find:
            return

        self.rlist.append(root)
        if root == node:
            self.find = 1
            if flag == 0:
                self.plist = self.rlist
            else:
                self.qlist = self.rlist

            return

        self.lca(root.left,node,flag)
        if self.find:
            return

        self.lca(root.right,node,flag)
        if self.find:
            return

        self.rlist.pop()

    def lowestCommonAncestor(self, root, p, q):
        self.rlist = []
        self.find = 0
        self.lca(root,p,0)

        self.rlist = []
        self.find = 0
        self.lca(root,q,1)

        mlen = min(len(self.plist), len(self.qlist)) - 1

        while self.plist[mlen] != self.qlist[mlen]:
            mlen -= 1

        return self.plist[mlen]
