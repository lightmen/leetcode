# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        arr = []
        cur_q = []
        next_q = []
        if root:
            cur_q.append(root)

        while cur_q:
            ele = []
            for node in cur_q:
                ele.append(node.val)
                if node.left:
                    next_q.append(node.left)
                if node.right:
                    next_q.append(node.right)

            cur_q = next_q
            next_q = []
            arr.append(ele)

        arr.reverse()

        return arr
