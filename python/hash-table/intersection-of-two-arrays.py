class Solution(object):
    def intersection(self, nums1, nums2):
        return [val for val in set(nums1) if val in nums2]
        #'return list(set(nums1) & set(nums2))' is also OK
