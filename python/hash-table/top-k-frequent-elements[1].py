class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        d = {}
        for val in nums:
            d[val] = d.get(val, 0) + 1

        res = []
        for val, count in sorted(d.items(), reverse=True, key=lambda x:x[1]):
            res.append(val)
            k -= 1
            if k == 0:
                break

        return res
