# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rescan(self, left_pre, left_in, count):
        if count <= 0:
            return None

        node = TreeNode(self.preorder[left_pre])
        node_pos = self.inorder.index(self.preorder[left_pre])

        node.left = self.rescan(left_pre + 1, left_in, node_pos - left_in)
        node.right = self.rescan(left_pre + 1 + (node_pos - left_in), \
            node_pos + 1, count - 1 - (node_pos - left_in))
        return node

    def buildTree(self, preorder, inorder):
        self.preorder = preorder
        self.inorder = inorder

        return self.rescan(0, 0, len(inorder))
