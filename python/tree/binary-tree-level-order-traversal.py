# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        self.ret = []

        if root is None:
            return self.ret

        q = [root]
        while q:
            tmp = []
            new_q = []
            for node in q:
                tmp.append(node.val)
                if node.left:
                    new_q.append(node.left)
                if node.right:
                    new_q.append(node.right)
            q = new_q
            self.ret.append(tmp)

        return self.ret
