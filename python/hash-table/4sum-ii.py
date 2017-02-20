class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        d1 = {}
        ret = 0;
        for a in A:
            for b in B:
                d1[a+b] = d1.get(a+b,0) + 1

        for c in C:
            for d in D:
                key = c + d
                ret += d1.get(-key, 0)

        return ret
