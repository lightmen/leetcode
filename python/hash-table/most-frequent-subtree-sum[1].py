# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.c = collections.Counter()

    def depth(self, root):
        if not root:
            return 0
        left = self.depth(root.left)
        right = self.depth(root.right)

        total = root.val + left + right
        self.c[total] += 1
        return total

    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.depth(root)
        maxfreq = max(self.c.values() + [None])

        return [k for k, v in self.c.items() if v == maxfreq]
