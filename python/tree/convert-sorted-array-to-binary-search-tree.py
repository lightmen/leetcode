# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def bsearch(self,start,end):
        if end < start:
            return None

        mid = (start + end) / 2
        node = TreeNode(self.nums[mid])
        node.left = self.bsearch(start,mid -1)
        node.right = self.bsearch(mid + 1, end)

        return node

    def sortedArrayToBST(self, nums):
        self.nums = nums
        return self.bsearch(0,len(self.nums) - 1)
