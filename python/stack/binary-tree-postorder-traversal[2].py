# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        st = []
        data = []
        pre = None

        if root:
            st.append(root)
            while st:
                cur = st[len(st)-1]
                if ((cur.left == None and cur.right == None) or \
                    (pre  and (pre == cur.left or pre == cur.right))):
                    data.append(cur.val)
                    st.pop()
                    pre = cur
                else:
                    if cur.right:
                        st.append(cur.right)
                    if cur.left:
                        st.append(cur.left)

        return data
