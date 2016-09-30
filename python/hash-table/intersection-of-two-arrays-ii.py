class Solution(object):
    def intersect(self, nums1, nums2):
        ret = []
        d = {}

        for val in nums1:
            if d.get(val):
                d[val] += 1
            else:
                d[val] = 1

        for val in nums2:
            if d.get(val,0) > 0:
                ret.append(val)
                d[val] -= 1

        return ret
