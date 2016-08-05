class Solution(object):
    def containsDuplicate(self, nums):
        nums.sort()
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                return True

        return False
