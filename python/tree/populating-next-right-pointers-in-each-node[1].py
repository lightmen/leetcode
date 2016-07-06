# Definition for binary tree with next pointer.
# class TreeLinkNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution(object):
    def connect(self, root):
        if root is None:
            return

        parent = root
        next = root.left
        while parent and next:
            pre = None
            while parent:
                if pre is None:
                    pre = parent.left
                else:
                    pre.next = parent.left
                    pre = pre.next
                pre.next = parent.right
                pre = pre.next
                parent = parent.next

            parent = next
            next = next.left
