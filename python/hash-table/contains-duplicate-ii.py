class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        d = {}
        for i in range(len(nums)):
            idx = d.get(nums[i])
            if idx >= 0 and i - idx <= k:
                return True

            d[nums[i]] = i

        return False
