# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.result = []

    def postorderTraversal(self, root):
        if not root:
            return self.result

        self.postorderTraversal(root.left)
        self.postorderTraversal(root.right)
        self.result.append(root.val)

        return self.result
