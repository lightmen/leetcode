# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        res = []
        st = []

        while root or st:
            while root:
                st.append(root)
                root = root.left

            root = st.pop()
            res.append(root.val)
            root = root.right

        return res
