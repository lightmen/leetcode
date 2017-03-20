class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        i, j = len(g) - 1, len(s) - 1
        g, s = sorted(g), sorted(s)
        ret = 0

        while min(i, j) >= 0:
            if s[j] >= g[i]:
                ret += 1
                j -= 1

            i -= 1

        return ret
