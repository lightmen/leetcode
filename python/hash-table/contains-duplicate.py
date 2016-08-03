class Solution(object):
    def containsDuplicate(self, nums):
        nums.sort()
        length = len(nums)

        for i in range(1,length):
            if nums[i] == nums[i-1]:
                return True

        return False
