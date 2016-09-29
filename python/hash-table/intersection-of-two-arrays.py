class Solution(object):
    def intersection(self, nums1, nums2):
        return [val for val in set(nums1) if val in nums2]
