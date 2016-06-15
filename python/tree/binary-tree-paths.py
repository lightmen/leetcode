# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def __init__(self):
        self.path = []

    def rescuive(self,root,cur_path):
        if not root:
            return

        cur_path += str(root.val)
        if not root.left and not root.right:
            self.path.append(cur_path)
            return

        cur_path += '->'
        if root.left:
            self.rescuive(root.left,cur_path)
        if root.right:
            self.rescuive(root.right,cur_path)

    def binaryTreePaths(self, root):
        self.rescuive(root,'')
        return self.path
