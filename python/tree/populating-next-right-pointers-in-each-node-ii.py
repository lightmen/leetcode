# Definition for binary tree with next pointer.
# class TreeLinkNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution(object):
    def get_next(self, root):
        while root and root.left == None and root.right == None:
            root = root.next

        return root

    def get_next_child(self,root):
        parent = self.get_next(root)
        if parent:
            return parent.left if parent.left else parent.right

        return None

    def connect(self, root):
        parent = self.get_next(root)
        next = self.get_next_child(root)

        while parent and next:
            while parent:
                if parent.left:
                    parent.left.next = parent.right if parent.right \
                        else self.get_next_child(parent.next)
                if parent.right:
                    parent.right.next = self.get_next_child(parent.next)

                parent = self.get_next(parent.next)

            parent = self.get_next(next)
            next = self.get_next_child(next)
