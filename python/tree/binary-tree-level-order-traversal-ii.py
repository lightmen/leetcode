# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        if not root:
            return []

        ret = []
        q = [root]
        while q:
            new_q = []
            li = []
            for node in q:
                li.append(node.val)
                if node.left:
                    new_q.append(node.left)
                if node.right:
                    new_q.append(node.right)
            q = new_q;
            ret.insert(0,li)

        return ret
