class Solution(object):
    def intersection(self, nums1, nums2):
        ret = []

        for val in set(nums1):
            if val in nums2:
                ret.append(val)

        return ret
