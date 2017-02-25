class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {0 : -1}
        cur_sum = 0
        res = 0

        for i in range(len(nums)):
            cur_sum += (2 * nums[i] - 1)
            if cur_sum in d:
                res = res if res > i - d[cur_sum] else i - d[cur_sum]
            else:
                d[cur_sum] = i

        return res
