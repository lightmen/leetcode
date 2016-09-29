class Solution(object):
    def intersection(self, nums1, nums2):
        ret = []
        d = {}

        for key in nums1:
            d[key] = 1

        for key in nums2:
            if d.get(key,0) == 1:
                ret.append(key)
                d[key] -= 1

        return ret
