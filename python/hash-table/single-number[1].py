class Solution(object):
    def singleNumber(self, nums):
        h = {}

        for val in nums:
            h[val] = 1 if h.get(val,-1) == -1 else 2

        for val in nums:
            if h[val] == 1:
                return val
