# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, root):
        if root is None:
            return 0,0

        left,not_left = self.dfs(root.left)
        right, not_right = self.dfs(root.right)

        cur = not_left + not_right + root.val
        not_cur = max(left,not_left) + max(right,not_right)

        return cur, not_cur

    def rob(self, root):
        cur,not_cur = self.dfs(root)

        return max(cur,not_cur)
