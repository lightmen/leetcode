class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for index, val in enumerate(nums):
            if target - val in d:
                return [d[target-val], index]
            d[val] = index

        return []
