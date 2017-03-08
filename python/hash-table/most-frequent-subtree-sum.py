# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.d = {}

    def depth(self, root):
        if not root:
            return 0
        left = self.depth(root.left)
        right = self.depth(root.right)

        total = root.val + left + right
        self.d[total] = self.d.get(total, 0) + 1
        return total

    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.depth(root)
        res = []
        prev = -1
        for value, count in sorted(self.d.items(), reverse=True, key=lambda x:x[1]):
            if prev == -1:
                prev = count
            if count == prev:
                res.append(value)
            else:
                break

        return res
