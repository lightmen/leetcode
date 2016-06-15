# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        st = []
        arr = []
        if root:
            st.append(root)

        while st:
            node = st.pop()
            arr.append(node.val)
            if node.right:
                st.append(node.right)
            if node.left:
                st.append(node.left)

        return arr
