# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        self.st = []
        self.cur = root

    def hasNext(self):
        return self.st or self.cur

    def next(self):
        while self.cur:
            self.st.append(self.cur)
            self.cur = self.cur.left

        tmp = self.st.pop()
        self.cur = tmp.right
        return tmp.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
