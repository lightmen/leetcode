class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        ret = 0
        plus = 0
        for c in s:
            d[c] = d.get(c,0) + 1

        for (key,count) in d.items():
            ret += count
            if count % 2 :
                ret -= 1
                plus = 1

        return ret + plus
