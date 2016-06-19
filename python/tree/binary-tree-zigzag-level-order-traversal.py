# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        left_first = 1
        st = []
        next_st = []
        arr = []

        if root:
            st.append(root)

        while st:
            ele = []
            while st:
                node = st.pop()
                ele.append(node.val)
                if left_first:
                    if node.left:
                        next_st.append(node.left)
                    if node.right:
                        next_st.append(node.right)
                else:
                    if node.right:
                        next_st.append(node.right)
                    if node.left:
                        next_st.append(node.left)

            left_first ^= 1
            arr.append(ele)
            st = next_st
            next_st = []

        return arr
