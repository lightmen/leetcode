# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def scan(self,in_pos, post_pos, count):
        if count <= 0:
            return None

        node = TreeNode(self.postorder[post_pos + count-1])
        idx = self.inorder.index(self.postorder[post_pos + count-1])

        node.left = self.scan(in_pos,post_pos,idx - in_pos)
        node.right = self.scan(idx+1,post_pos + idx - in_pos,count - 1 -idx + in_pos)
        return node

    def buildTree(self, inorder, postorder):
        self.inorder = inorder
        self.postorder = postorder

        return self.scan(0,0,len(self.inorder))
