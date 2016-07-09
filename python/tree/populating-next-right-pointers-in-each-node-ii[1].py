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
        while parent:
            first, last = None, None
            while parent:
                for node in [parent.left, parent.right]:
                    if node is None:
                        continue
                    if first is None:
                        first = node
                        last = node
                        continue
                    last.next = node
                    last = node

                parent = parent.next

            parent = first
