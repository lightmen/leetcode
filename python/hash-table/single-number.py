class Solution(object):
    def singleNumber(self, nums):
        ret = 0
        for val in nums:
            ret ^= val

        return ret
