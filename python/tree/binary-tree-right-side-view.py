# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        result = []

        arr = []
        if root:
            arr.append(root)

        while arr:
            result.append(arr[-1].val)
            next_arr = []
            for node in arr:
                if node.left:
                    next_arr.append(node.left)
                if node.right:
                    next_arr.append(node.right)
            arr = next_arr

        return result
