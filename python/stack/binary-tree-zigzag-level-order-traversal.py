# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        cur_st = []
        next_st = []
        data = []
        left2right = 0

        if root:
            cur_st.append(root)

        while cur_st:
            cur_data = []
            while cur_st:
                node = cur_st.pop()
                if left2right:
                    if node.right:
                        next_st.append(node.right)
                    if node.left:
                        next_st.append(node.left)
                else:
                    if node.left:
                        next_st.append(node.left)
                    if node.right:
                        next_st.append(node.right)

                cur_data.append(node.val)

            data.append(cur_data)
            left2right ^= 1
            cur_st = next_st
            next_st = []

        return data
